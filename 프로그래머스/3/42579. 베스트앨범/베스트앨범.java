import java.util.*;

class Solution {
    
    static class Song{
        int index;
        int play;
        
        Song(int index, int play){
            this.index = index;
            this.play = play;
        }
    }
    
    public int[] solution(String[] genres, int[] plays) {
        Map<String, Integer> genreTotalPlay = new HashMap<>();
        Map<String, List<Song>> genreSongs = new HashMap<>();
        
        for(int i=0;i<genres.length;i++){
            String genre = genres[i];
            int play = plays[i];
            
            genreTotalPlay.put(genre, genreTotalPlay.getOrDefault(genre, 0) + play);
            genreSongs.putIfAbsent(genre, new ArrayList<>());
            genreSongs.get(genre).add(new Song(i, play));
        }
        
        List<String> sortedGenres = new ArrayList<>(genreTotalPlay.keySet());
        sortedGenres.sort((x, y) -> genreTotalPlay.get(y) - genreTotalPlay.get(x));
        
        List<Integer> answerList = new ArrayList<>();
        
        for(String genre : sortedGenres){
            List<Song> songs = genreSongs.get(genre);
            
            songs.sort((x, y) -> {
                if(y.play==x.play){
                    return x.index - y.index;
                }
                return y.play - x.play;
            });
            
            for(int i=0;i<Math.min(2, songs.size()); i++){
                answerList.add(songs.get(i).index);
            }
        }
        
        int[] answer = new int[answerList.size()];
        for(int i=0;i<answerList.size();i++){
            answer[i] = answerList.get(i);
        }
        
        return answer;
        
    }
}