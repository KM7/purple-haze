var return_val;
function get_update_JSON(){
$.ajax({url: "https://api.mlab.com/api/1/databases/p-fire/collections/purplegarage?apiKey=ge3hUcuINpHsOkUhoayG7tL2vTpkrETR", success: function(result){
        return_val=result;
    }});
}