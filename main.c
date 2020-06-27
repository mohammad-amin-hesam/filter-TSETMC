// فیلتر صف خرید

/*
(qd1) > (bvol) &&
(pd1) == (tmax) &&
(tvol) > (bvol) &&
(qvol) == 0
*/

// فیلتر صف خرید کم حجم
/*
(pd1) == (tmax) &&
(qd1) > 0.3 * (bvol) &&
(pd1) < (bvol)
*/

// صف فروش
/*
(qo1) > (bvol) &&
(po1) == (tmin) &&
(tvol) > (bvol) &&
(qd1) == 0
*/


// صف خرید و صف فروش
/*
true==function() {
  // صف خرید
  if(
    (qd1) > (bvol) &&
    (pd1) == (tmax) &&
    (tvol) > (bvol) &&
    (qvol) == 0
    ) {
      (cfield0) = "صف خرید";
      return true;
    }
  // صف فروش
  if(
    (qo1) > (bvol) &&
    (po1) == (tmin) &&
    (tvol) > (bvol) &&
    (qd1) == 0
  ) {
    (cfield0) = "صف فروش";
    return true;
  }
  // صف خرید کم حجم
  if(
    (pd1) == (tmax) &&
    (qd1) > 0.3 * (bvol) &&
    (pd1) < (bvol)
  ) {
    (cfield0) = "صف خرید کم حجم";
    return true;
  }
}()
*/

// RSI = 100 - (100 / (1 + RS))

// RS = (Total Gains/n) / (Total Lossess/n)

// فیلتر محاسبه RSI
/*
true==function()
{

   var CalculateRSI =function(period){

      var len=20;

      for (var i = 0; i < len ; i++) {
         var rec=[ih][len-1-i];

         var change=rec.PClosing-rec.PriceYesterday;        

         if (change> 0) {
        rec.gain=change;
                rec.loss=0;
         }
         else
         {
        rec.gain=0;
                rec.loss=-change;
         }
      }

      // Calculate first "average gain" and "average loss"
      var gainSum=0;
      var lossSum=0;

      for (var i = 0; i < period; i++) {
         var rec=[ih][len-1-i];
     gainSum += rec.gain;
     lossSum += rec.loss;
      }

      var averageGain=gainSum /period;
      var averageLoss=lossSum / period;

      // Calculate subsequent "average gain" and "average loss" values
      for (var i = period + 1; i < len; i++) {
         var rec=[ih][len-1-i];

         averageGain=(averageGain* (period - 1) + rec.gain) / period;
         averageLoss=(averageLoss* (period - 1) + rec. loss)/  period;

         rec.averageGain=averageGain;
         rec.averageLoss=averageLoss;
      }

      // Calculate RSI
     
      var RS = 0;                       // Relative strength
      var RSIndex = 0;             // Relative strength index
       
      for (var i = period + 1; i < len; i++) {
         var rec=[ih][len-1-i];

         RS = rec.averageGain/ rec.averageLoss;
     RSIndex = 100 - 100 / (1 + RS);
     rec.rsi=RSIndex;
      }
   };

      if(typeof [ih][0].rsi=="undefined") 
        CalculateRSI(14);

        (cfield0)= AdvRoundColor([ih][0].rsi,1); 

         return true;      

}
()
 
*/

// سهم آماده نوسان و قابل برگشت
/*
  (pcp) < -3 &&
  (plp) > -3
*/