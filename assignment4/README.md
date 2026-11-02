I started by cloning the GlobalSums repository aswell as pulling from the course repository. I opened week-05 in course repository and saw the 
skeleton and also how I should add the 4 sum methods we will test. Before I started adding any methods I copied the skeleton to my folder. After
that I ran make command and got an error. After finding out what it means, I had to add -lm at the end of one of the lines to resolve it, 
because both c files compiled but the linking didn't work I got 'undefined reference to 'pow''. Neither of the .c files had code for pow
function they just knew that it ecists. THe actual code is in a library that gcc doesnt include so we had to run -lm to get it. After that
I took one by one all the 4 methods that the assignment task mentioned. Before that I inspected the baseline and understood why it performs bad and
it's because double can hold only 16 digits. If we already have some large sums and we try to add a small number that has more digits than digits
left in the sum it will just round it up aka sometimes not even add it to the sum. After that I added the ldsum algorithm to the alogithms file and 
defined it in the header file. The ldsum is similar to the baseline just instead of using double it uses long double, it reduces the erorr but
again we have the problem with digits same as in the baseline. After reading the code I went to the main file and added the print block just like 
in skeleton but instead of sum I called ldsum. Also I had to create sperate accurate_sum and current_sum variables since the function returns 
long double and my accurate and current sums were double. After that I went over the pairwise sum. It takes the array and reduces it in each 
iteration by 2 until we have one number left. It sums the first and second number then third and fourth so it sums them up in pairs. This 
method works because we first add all the small numbers one to each other. We dont have this big sum like in baseline and the ldsum that already 
takes some digits spaces. I noticed that this is the first algorithm with 0 diff aka error. The implementation was the same I added it to the
algorithms file and header, and in main I copied the print block just instead of calling baseline sum function I called pairwise. There was no need
to create additional variables since it returns double and we already have doubles. After that I turned to kahan. It works in a way that it doesnt
add the small numbers to the sum. It has a correction variable that tracks wether we added the number or not. The new sum computes the sum like
we would in baseline and it rounds numbers so we iterate until the sum + correction rounds to a digit bigger.Basically we trach the error and add it to the sum when possible. Steps were the same alogirhtms file header and main ones got edited just
it to the sum like in previous algorithms. Then I turned to knuth and to be honest I dont understand it completely. It seems like its doing the
similar thing as kahan.I believe that the general idea is the same.All of these wrong sum algorithms create problems for parallelization.
Here (a + b) + c might give different result then a + (b + c) and parallelization is all about computing multiple steps in parallel and combining
them. By running ./sum_test I got the results and i concluded that ld sum is better than the baseline one but still it has some error, and the 
pairwise, knuth and khan have 0 error meaning they are precise. Pairwise take some more time and knuth and kahan take the longest. 
Link to the spreadsheet: https://docs.google.com/spreadsheets/d/1JNEPipKmSG4Y-Wxw0wV-Fktct5RQ--_A99p_Flgf6tE/edit


