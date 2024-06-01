function x = gauss_seidel(A, b, x, iters)
    for i = 1:iters
        for j = 1:size(A,1)
            x(j) = (b(j) - sum(A(j,:)'.*x) + A(j,j)*x(j)) / A(j,j);
        end
    end
end