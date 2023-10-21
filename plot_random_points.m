function plot_random_points
    st_tock = 10000;
    tocke_na_loku = @(kot, radij) [radij * cos(kot); radij * sin(kot)];
    x = -1 + 2 * rand(1, st_tock);
    y = -1 + 2 * rand(1, st_tock);
    znotraj_kroga = (x.^2 + y.^2 <= 1);
    tocke_v_krogu = [x(znotraj_kroga); y(znotraj_kroga)];
    tocke_iz_kroga = [x(~znotraj_kroga); y(~znotraj_kroga)];

    figure;
    hold on;
    scatter(tocke_v_krogu(1, :), tocke_v_krogu(2, :), 'g', 'filled'); 
    scatter(tocke_iz_kroga(1, :), tocke_iz_kroga(2, :), 'r', 'x'); 
    kot1 = linspace(0, 2 * pi, 100); 
    radij1 = 1;
    tocke_lok = tocke_na_loku(kot1, radij1);

    plot(tocke_lok(1, :), tocke_lok(2, :), 'k', 'LineWidth', 2); 

    axis equal;
    title('Naključno generirane točke');
    legend('Znotraj krožnice', 'Izven krožnice');
    xlabel('x os');
    ylabel('y os');

    hold off;
end
