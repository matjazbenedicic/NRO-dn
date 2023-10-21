function [tocke_v_krogu, tocke_v_kvadratu] = mcc_pi(st_tock)

    x = -1 + 2 * rand(1, st_tock);
    y = -1 + 2 * rand(1, st_tock);
    znotraj_kroga = (x.^2 + y.^2 <= 1);
    tocke_v_krogu = [x(znotraj_kroga); y(znotraj_kroga)];
    tocke_v_kvadratu = [x; y];

end




