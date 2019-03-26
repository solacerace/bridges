import math
import numpy as np
import pandas as pd
import scipy.optimize as opt
import pandas_datareader.data as web
import matplotlib.pyplot as plt
from scipy.stats import norm


def get_ret_vol_sr(weights):
    weights = np.array(weights)
    portfolio_return = np.sum(mean_daily_returns.T * weights) 
    portfolio_std_dev = np.sqrt(np.dot(weights.T,np.dot(cov_matrix, weights))) 
    sr = portfolio_return/portfolio_std_dev
    return np.array([portfolio_return, portfolio_std_dev, sr])

def neg_sharpe(weights):
# the number 2 is the sharpe ratio index from the get_ret_vol_sr
    return get_ret_vol_sr(weights)[2] * -1

def check_sum(weights):
    #return 0 if sum of the weights is 1
    return np.sum(weights)-1

def minimize_volatility(weights):
    return get_ret_vol_sr(weights)[1]

def another_method():
    cons = ({'type':'eq', 'fun':check_sum})
    bounds = ((0,1), (0,1), (0,1))
    init_guess = (0.33, 0.33, 0.34)
    opt_results = opt.minimize(neg_sharpe, init_guess, method='SLSQP', bounds= bounds, constraints=cons)
    print(opt_results)
    result = get_ret_vol_sr(opt_results.x)
    print('result = ', result)

def draw_efficientportfolio():
    cons = ({'type':'eq', 'fun':check_sum})
    bounds = ((0,1), (0,1), (0,1))
    init_guess = (0.33, 0.33, 0.34)

    frontier_y = np.linspace(0.09, 0.31, 200)
    #frontier_y = np.linspace(0, 0.06, 200)
    frontier_x = []
    for possible_return in frontier_y:
        cons = ({'type':'eq', 'fun':check_sum},
                {'type':'eq', 'fun': lambda w: get_ret_vol_sr(w)[0] - possible_return})
        
        result = opt.minimize(minimize_volatility,init_guess,method='SLSQP', bounds=bounds, constraints=cons)
        frontier_x.append(result['fun'])
    
    plt.plot(frontier_x,frontier_y, 'b--', linewidth=3)


def getVARxESx(weights):
    x = np.matrix(weights).T
    print('x ', x)
    print('mu ', mu)
    print('Sigma ', Sigma)

    VAR_x = -x.T*mu + norm.ppf(alpha)*math.sqrt(x.T*Sigma*x)
    #VAR_x = x.T*mu + norm.ppf(1-alpha)*math.sqrt(x.T*Sigma*x)

    
    ES_x = -x.T*mu + ((math.sqrt(x.T*Sigma*x))/(1-alpha))*norm.pdf(norm.ppf(alpha))
    #ES_x = x.T*mu - (math.sqrt(x.T*Sigma*x))/(1-alpha)*norm.pdf(norm.ppf(1-alpha))

    return np.linalg.det(VAR_x), np.linalg.det(ES_x)



#list of stocks in portfolio
stocks = ['A','B','C']


dataMean = {'A' : 30/100, 'B' : 20/100, 'C' : 10/100}
mean_daily_returns = pd.Series(dataMean)
mu = np.matrix(mean_daily_returns).T
print('mu.shape ', mu.shape)
#mean_daily_returns = np.array([30/100, 20/100, 10/100]]) 

vol = np.matrix([[20/100], [15/100], [10/100]])
#print('vol  = ', vol )

rho = np.matrix([[1, -0.3, -0.5],
[-0.3, 1, -0.6],
[-0.5, -0.6, 1]])

eigenvalueOfRho = np.linalg.eigvals(rho)
print('eigenvalueOfRho = ', eigenvalueOfRho)

S = np.diagflat(vol)
Sigma = S*rho*S 
print('Sigma=', Sigma)

cov_matrix = pd.DataFrame(Sigma)

print('cov_matrix', cov_matrix)

#set number of runs of random portfolio weights
num_portfolios = 1000
 
#set up array to hold results
#We have increased the size of the array to hold the weight values for each stock
results = np.zeros((6+len(stocks)-1,num_portfolios))

alpha=0.95 
for i in range(num_portfolios):
    #select random weights for portfolio holdings
    weights = np.array(np.random.random(3))
    #rebalance weights to sum to 1
    weights /= np.sum(weights)
    
    print('weights.shape ', weights.shape)
    print('mean_daily_returns.shape ', mean_daily_returns.shape) 
    print('Sigma.shape ', Sigma.shape) 
    
    #calculate portfolio return and volatility
    portfolio_return = np.sum(mean_daily_returns.T * weights) 
    #print('cov_matrix ', cov_matrix)
    #print('weights ', weights)
    portfolio_std_dev = np.sqrt(np.dot(weights.T,np.dot(cov_matrix, weights))) 
    
    #store results in results array
    results[0,i] = portfolio_return
    results[1,i] = portfolio_std_dev
    #store Sharpe Ratio (return / volatility) - risk free rate element excluded for simplicity
    results[2,i] = results[0,i] / results[1,i]

    # STEP 2 calculations
    # compute VAR
    
    print('mean_daily_returns.shape ', mean_daily_returns.shape)
    print('weights.shape ', weights.shape)
    print('Sigma.shape ', Sigma.shape)
    
    wm = np.dot(weights.T, mean_daily_returns)
    print('wm ', wm)
    print('wm.shape ', wm.shape)
    
    VAR_x, ES_x = getVARxESx(weights)

    # VAR
    results[3,i] = VAR_x

    # ES
    results[4,i] = ES_x

    #iterate through the weight vector and add data to results array
    for j in range(len(weights)):
        results[j+5,i] = weights[j]
 
#convert results array to Pandas DataFrame
#results_frame = pd.DataFrame(results.T,columns=['ret','stdev','sharpe',stocks[0],stocks[1],stocks[2],stocks[3]])
results_frame = pd.DataFrame(results.T,columns=['ret','stdev','sharpe','VAR', 'ES',stocks[0],stocks[1],stocks[2]])
 
#locate position of portfolio with highest Sharpe Ratio
max_sharpe_port = results_frame.iloc[results_frame['sharpe'].idxmax()]
#locate positon of portfolio with minimum standard deviation
min_vol_port = results_frame.iloc[results_frame['stdev'].idxmin()]
VAR_max_port = results_frame.iloc[results_frame['VAR'].idxmax()]
VAR_min_port = results_frame.iloc[results_frame['VAR'].idxmin()]
ES_max_port = results_frame.iloc[results_frame['ES'].idxmax()]
ES_min_port = results_frame.iloc[results_frame['ES'].idxmin()]

#create scatter plot coloured by Sharpe Ratio
plt.scatter(results_frame.stdev,results_frame.ret,c=results_frame.sharpe,cmap='RdYlBu')
plt.xlabel('Volatility')
plt.ylabel('Returns')
plt.colorbar()

#plot green star to highlight position of minimum variance portfolio
plt.scatter(min_vol_port[1],min_vol_port[0],marker=(5,1,0),color='g',s=1000)
print('Global Min Variance Portfolio = ', min_vol_port[5:] )
print('max_sharpe_ratio Portfolio = ', max_sharpe_port[5:] )
print('max_sharpe_ratio  = ', max_sharpe_port[2] )
print('VAR_max_port = ', VAR_max_port[0:] )
print('VAR_min_port = ', VAR_min_port[0:] )
print('ES_max_port = ', ES_max_port[0:] )
print('ES_min_port = ', ES_min_port[0:] )


draw_efficientportfolio()
plt.show()

