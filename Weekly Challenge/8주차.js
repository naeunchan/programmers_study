function solution(sizes) {
    let wMax = 0;
    let hMax = 0;
    
    sizes.forEach((card) => {
        card.sort((a, b) => a - b);
        
        wMax = Math.max(wMax, card[0]);
        hMax = Math.max(hMax, card[1]);
    });
    
    return wMax * hMax;
}