struct pnt {
    long long x; long long y;
};
long long cross_product(pnt vec_ab, pnt vec_cd){
    // vec_ab(x1,y1)とvec_cd(x2,y2)の外積を計算
    return vec_ab.x * vec_cd.y - vec_ab.y * vec_cd.x; 
}
bool is_intersect(pnt a, pnt b, pnt c, pnt d){
    // 平面上の線分abと線分cdが交わるか判定
    pnt vec_ab = {b.x - a.x, b.y - a.y};
    pnt vec_ac = {c.x - a.x, c.y - a.y};
    pnt vec_ad = {d.x - a.x, d.y - a.y};
    pnt vec_cd = {d.x - c.x, d.y - c.y};
    pnt vec_ca = {a.x - c.x, a.y - c.y};
    pnt vec_cb = {b.x - c.x, b.y - c.y};
    long long ab_ac = cross_product(vec_ab, vec_ac);
    long long ab_ad = cross_product(vec_ab, vec_ad);
    long long cd_ca = cross_product(vec_cd, vec_ca);
    long long cd_cb = cross_product(vec_cd, vec_cb);
    return ab_ac * ab_ad < 0 and cd_ca * cd_cb < 0;
}