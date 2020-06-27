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