#pragma once
namespace Eloquent {
    namespace ML {
        namespace Port {
            class PCA {
                public:
                    /**
                    * Apply dimensionality reduction
                    * @warn Will override the source vector if no dest provided!
                    */
                    void transform(double *x, double *dest = NULL) {
                        static double u[5] = { 0 };
                        u[0] = dot(x,   0.02374934414  , -0.034805683716  , -0.052129967935  , -0.010473990491  , 0.018098676585  , 0.035218225424  , 0.04976367442  , 0.057295932847  , 0.074799122179  , 0.065712934033  , 0.07596557488  , 0.062729588642  , 0.076371316703  , 0.069074317017  , 0.066598834224  , 0.069057614642  , 0.078990623167  , 0.082809539245  , 0.079460416667  , 0.079168745975  , 0.089173332314  , 0.086689065432  , 0.10021457099  , 0.094020070685  , 0.095259693419  , 0.105259998802  , 0.087327907348  , 0.10709517245  , 0.104342191854  , 0.105249382677  , 0.131629526002  , 0.100241270348  , 0.11379646765  , 0.108393649759  , 0.096860571675  , 0.101861944098  , 0.082359174095  , 0.087715313012  , 0.07819027627  , 0.072252166114  , 0.066818592429  , 0.061115676843  , 0.055638325258  , 0.047968949588  , 0.041309477882  , 0.036091367822  , 0.03031170147  , 0.02448994128  , 0.016384785004  , 0.009842752625  , -0.000111117016  , -0.006703759803  , -0.016309988967  , -0.023848375795  , -0.03167452053  , -0.0363221415  , -0.038697148871  , -0.040919789099  , -0.044417458599  , -0.05116650459  , -0.054620800891  , -0.063542432492  , -0.077321520703  , -0.088743450358  , -0.097581207428  , -0.106716830512  , -0.113482325428  , -0.118768524799  , -0.11740722791  , -0.115868443967  , -0.107870399382  , -0.099735600172  , -0.092053766639  , -0.086693613601  , -0.079387138798  , -0.07521426494  , -0.07142030391  , -0.066670513305  , -0.06058180242  , -0.060853891447  , -0.056241285075  , -0.054485285013  , -0.049666413312  , -0.048156908373  , -0.044398251901  , -0.039415411123  , -0.036964591731  , -0.033376266969  , -0.033997456854  , -0.031926260693  , -0.031088194514  , -0.029506558807  , -0.028584963475  , -0.026141684193  , -0.026551524201  , -0.025113339347  , -0.024772013605  , -0.022415207241  , -0.023408144052  , -0.022899518651  , -0.024261206885  , -0.022230023112  , -0.02368900803  , -0.023468376197  , -0.023141011027  , -0.022134612052  , -0.024631392323  , -0.02362499986  , -0.024717938691  , -0.024608754102  , -0.025116325199  , -0.024553863914  , -0.0242057568  , -0.02552596075  , -0.025613737761  , -0.024408863211  , -0.024332375928  , -0.022556371587  , -0.021023164225  , -0.017379273191  , -0.015473173937  , -0.014772247487  , -0.0127591517  , -0.011679866837  , -0.01053225184  , -0.007823715581  , -0.006275089657  , -0.005436512716  , -0.007388628348  , -0.005436512716  , -0.006275089657  , -0.007823715581  , -0.01053225184  , -0.011679866837  , -0.0127591517  , -0.014772247487  , -0.015473173937  , -0.017379273191  , -0.021023164225  , -0.022556371587  , -0.024332375928  , -0.024408863211  , -0.025613737761  , -0.02552596075  , -0.0242057568  , -0.024553863914  , -0.025116325199  , -0.024608754102  , -0.024717938691  , -0.02362499986  , -0.024631392323  , -0.022134612052  , -0.023141011027  , -0.023468376197  , -0.02368900803  , -0.022230023112  , -0.024261206885  , -0.022899518651  , -0.023408144052  , -0.022415207241  , -0.024772013605  , -0.025113339347  , -0.026551524201  , -0.026141684193  , -0.028584963475  , -0.029506558807  , -0.031088194514  , -0.031926260693  , -0.033997456854  , -0.033376266969  , -0.036964591731  , -0.039415411123  , -0.044398251901  , -0.048156908373  , -0.049666413312  , -0.054485285013  , -0.056241285075  , -0.060853891447  , -0.06058180242  , -0.066670513305  , -0.07142030391  , -0.07521426494  , -0.079387138798  , -0.086693613601  , -0.092053766639  , -0.099735600172  , -0.107870399382  , -0.115868443967  , -0.11740722791  , -0.118768524799  , -0.113482325428  , -0.106716830512  , -0.097581207428  , -0.088743450358  , -0.077321520703  , -0.063542432492  , -0.054620800891  , -0.05116650459  , -0.044417458599  , -0.040919789099  , -0.038697148871  , -0.0363221415  , -0.03167452053  , -0.023848375795  , -0.016309988967  , -0.006703759803  , -0.000111117016  , 0.009842752625  , 0.016384785004  , 0.02448994128  , 0.03031170147  , 0.036091367822  , 0.041309477882  , 0.047968949588  , 0.055638325258  , 0.061115676843  , 0.066818592429  , 0.072252166114  , 0.07819027627  , 0.087715313012  , 0.082359174095  , 0.101861944098  , 0.096860571675  , 0.108393649759  , 0.11379646765  , 0.100241270348  , 0.131629526002  , 0.105249382677  , 0.104342191854  , 0.10709517245  , 0.087327907348  , 0.105259998802  , 0.095259693419  , 0.094020070685  , 0.10021457099  , 0.086689065432  , 0.089173332314  , 0.079168745975  , 0.079460416667  , 0.082809539245  , 0.078990623167  , 0.069057614642  , 0.066598834224  , 0.069074317017  , 0.076371316703  , 0.062729588642  , 0.07596557488  , 0.065712934033  , 0.074799122179  , 0.057295932847  , 0.04976367442  , 0.035218225424  , 0.018098676585  , -0.010473990491  , -0.052129967935  , -0.034805683716 );
                        u[1] = dot(x,   0.571823599626  , 0.164997554887  , 0.173913846429  , 0.200479160215  , 0.185789237199  , 0.166668902832  , 0.142995031778  , 0.132449274805  , 0.117860422199  , 0.117689170702  , 0.092559899422  , 0.079142807728  , 0.053172601022  , 0.050056850285  , 0.050855104256  , 0.036891349261  , 0.024883881781  , 0.022004168783  , 0.010498728859  , -0.000546815847  , -0.023562569221  , -0.03398139183  , -0.047721696437  , -0.045527665943  , -0.054858539466  , -0.063516899113  , -0.047089061852  , -0.065258246374  , -0.05919805842  , -0.063433782424  , -0.080548957851  , -0.047602479627  , -0.064685821771  , -0.06483417401  , -0.059057342093  , -0.059955107997  , -0.041115292119  , -0.05003993604  , -0.038793925967  , -0.031645001006  , -0.032063818447  , -0.026817373246  , -0.024831314342  , -0.024305759908  , -0.027596771411  , -0.028229909701  , -0.021905891416  , -0.020147626188  , -0.017219096658  , -0.016363954518  , -0.022510023529  , -0.025921716937  , -0.029097348449  , -0.034160072574  , -0.030169539543  , -0.028458907909  , -0.02512336811  , -0.020085733813  , -0.017545962788  , -0.016490238098  , -0.021080603672  , -0.02293380211  , -0.026728770859  , -0.027964205051  , -0.035899319342  , -0.040494781033  , -0.042759140678  , -0.038906188453  , -0.030940748543  , -0.032215076241  , -0.028401073041  , -0.022393215301  , -0.017286032324  , -0.012548085581  , -0.011364484141  , -0.011919388601  , -0.010907433394  , -0.009369203694  , -0.01312076878  , -0.009338725042  , -0.007481025241  , -0.002234526231  , -0.002515063566  , -0.000550039186  , -0.00097571643  , -0.002692760434  , -0.001128473203  , -0.002333926718  , -0.001301470852  , 0.002624321628  , 0.004592433851  , 0.005684498794  , 0.009539124117  , 0.009018099358  , 0.007221227513  , 0.006507937919  , 0.003154292839  , 0.002070570501  , 4.4382507e-05  , -0.000712547646  , -0.001716521871  , -0.003503397689  , -0.002113193974  , -0.004969826214  , -0.004677158712  , -0.006874200518  , -0.008343263993  , -0.009234036926  , -0.010343462036  , -0.010388931089  , -0.008731579188  , -0.009495019439  , -0.010911188904  , -0.009244490287  , -0.011199780806  , -0.009679174444  , -0.009676834176  , -0.007422782048  , -0.004846771824  , -0.004774397294  , -0.002418418001  , -0.000403240102  , -0.000454023671  , 0.002529358646  , 0.0040364242  , 0.002756867438  , 0.00188530576  , 0.001066212809  , 0.000769262905  , 0.001066212809  , 0.00188530576  , 0.002756867438  , 0.0040364242  , 0.002529358646  , -0.000454023671  , -0.000403240102  , -0.002418418001  , -0.004774397294  , -0.004846771824  , -0.007422782048  , -0.009676834176  , -0.009679174444  , -0.011199780806  , -0.009244490287  , -0.010911188904  , -0.009495019439  , -0.008731579188  , -0.010388931089  , -0.010343462036  , -0.009234036926  , -0.008343263993  , -0.006874200518  , -0.004677158712  , -0.004969826214  , -0.002113193974  , -0.003503397689  , -0.001716521871  , -0.000712547646  , 4.4382507e-05  , 0.002070570501  , 0.003154292839  , 0.006507937919  , 0.007221227513  , 0.009018099358  , 0.009539124117  , 0.005684498794  , 0.004592433851  , 0.002624321628  , -0.001301470852  , -0.002333926718  , -0.001128473203  , -0.002692760434  , -0.00097571643  , -0.000550039186  , -0.002515063566  , -0.002234526231  , -0.007481025241  , -0.009338725042  , -0.01312076878  , -0.009369203694  , -0.010907433394  , -0.011919388601  , -0.011364484141  , -0.012548085581  , -0.017286032324  , -0.022393215301  , -0.028401073041  , -0.032215076241  , -0.030940748543  , -0.038906188453  , -0.042759140678  , -0.040494781033  , -0.035899319342  , -0.027964205051  , -0.026728770859  , -0.02293380211  , -0.021080603672  , -0.016490238098  , -0.017545962788  , -0.020085733813  , -0.02512336811  , -0.028458907909  , -0.030169539543  , -0.034160072574  , -0.029097348449  , -0.025921716937  , -0.022510023529  , -0.016363954518  , -0.017219096658  , -0.020147626188  , -0.021905891416  , -0.028229909701  , -0.027596771411  , -0.024305759908  , -0.024831314342  , -0.026817373246  , -0.032063818447  , -0.031645001006  , -0.038793925967  , -0.05003993604  , -0.041115292119  , -0.059955107997  , -0.059057342093  , -0.06483417401  , -0.064685821771  , -0.047602479627  , -0.080548957851  , -0.063433782424  , -0.05919805842  , -0.065258246374  , -0.047089061852  , -0.063516899113  , -0.054858539466  , -0.045527665943  , -0.047721696437  , -0.03398139183  , -0.023562569221  , -0.000546815847  , 0.010498728859  , 0.022004168783  , 0.024883881781  , 0.036891349261  , 0.050855104256  , 0.050056850285  , 0.053172601022  , 0.079142807728  , 0.092559899422  , 0.117689170702  , 0.117860422199  , 0.132449274805  , 0.142995031778  , 0.166668902832  , 0.185789237199  , 0.200479160215  , 0.173913846429  , 0.164997554887 );
                        u[2] = dot(x,   0.049723500555  , 0.036407492039  , 0.015233629585  , 0.027576155785  , 0.040426616159  , 0.011912248315  , -0.014123776408  , -0.017897354038  , -0.036205406851  , -0.032576731299  , -0.030447537906  , -0.01526276696  , -0.016053509514  , -0.009674347779  , -0.013631538322  , -0.021284534631  , -0.035776409531  , -0.041144668687  , -0.037030323532  , -0.030114177235  , -0.033359427099  , -0.025668785977  , -0.03661129967  , -0.031877880401  , -0.032351101101  , -0.04040257885  , -0.026100292362  , -0.039483911622  , -0.029329239831  , -0.02684519373  , -0.044943649298  , -0.021485730832  , -0.029098285212  , -0.022897506939  , -0.01467240709  , -0.018658231311  , -0.003977097276  , 0.001833614317  , 0.014808132847  , 0.021394671603  , 0.031719353189  , 0.036837675852  , 0.042959205028  , 0.049312483172  , 0.061750708039  , 0.069244163285  , 0.07021059437  , 0.069235765986  , 0.07322800093  , 0.085666241505  , 0.112493251467  , 0.137588739935  , 0.170453845035  , 0.19559431764  , 0.207336407002  , 0.200436453772  , 0.183928794025  , 0.166700094639  , 0.151950320461  , 0.144333934599  , 0.13275613733  , 0.114855321272  , 0.078825302701  , 0.035412472105  , 0.002736262944  , -0.023881192791  , -0.045140600503  , -0.073198414544  , -0.07924449865  , -0.091930304303  , -0.086993228127  , -0.082651849887  , -0.077502675983  , -0.074664954586  , -0.072678605902  , -0.067650237754  , -0.066304710835  , -0.057878495333  , -0.059202660753  , -0.056043908775  , -0.055351393914  , -0.053073945664  , -0.047392563254  , -0.043128673583  , -0.044957789212  , -0.043891085583  , -0.04474352265  , -0.039945757813  , -0.039984296022  , -0.037417423337  , -0.033592340015  , -0.030611573676  , -0.029433116884  , -0.028945364477  , -0.026100668932  , -0.025477484588  , -0.027724109678  , -0.026399959127  , -0.025179834814  , -0.023029529325  , -0.020072743537  , -0.019974249904  , -0.019637647235  , -0.016440275616  , -0.017238479511  , -0.018445519494  , -0.023339746661  , -0.01718575337  , -0.012965376252  , -0.016299810299  , -0.010933222681  , -0.008380854187  , -0.010524361866  , -0.007151342078  , -0.008860449151  , -0.006600634506  , -0.003123435015  , -0.002134259988  , -0.002177103794  , -0.000887699386  , -0.000738778637  , -0.001402760969  , -0.001987728717  , -0.001416642489  , 0.002009213767  , -0.000467682448  , 0.000155223588  , -0.002315163265  , -0.002300801886  , -0.002315163265  , 0.000155223588  , -0.000467682448  , 0.002009213767  , -0.001416642489  , -0.001987728717  , -0.001402760969  , -0.000738778637  , -0.000887699386  , -0.002177103794  , -0.002134259988  , -0.003123435015  , -0.006600634506  , -0.008860449151  , -0.007151342078  , -0.010524361866  , -0.008380854187  , -0.010933222681  , -0.016299810299  , -0.012965376252  , -0.01718575337  , -0.023339746661  , -0.018445519494  , -0.017238479511  , -0.016440275616  , -0.019637647235  , -0.019974249904  , -0.020072743537  , -0.023029529325  , -0.025179834814  , -0.026399959127  , -0.027724109678  , -0.025477484588  , -0.026100668932  , -0.028945364477  , -0.029433116884  , -0.030611573676  , -0.033592340015  , -0.037417423337  , -0.039984296022  , -0.039945757813  , -0.04474352265  , -0.043891085583  , -0.044957789212  , -0.043128673583  , -0.047392563254  , -0.053073945664  , -0.055351393914  , -0.056043908775  , -0.059202660753  , -0.057878495333  , -0.066304710835  , -0.067650237754  , -0.072678605902  , -0.074664954586  , -0.077502675983  , -0.082651849887  , -0.086993228127  , -0.091930304303  , -0.07924449865  , -0.073198414544  , -0.045140600503  , -0.023881192791  , 0.002736262944  , 0.035412472105  , 0.078825302701  , 0.114855321272  , 0.13275613733  , 0.144333934599  , 0.151950320461  , 0.166700094639  , 0.183928794025  , 0.200436453772  , 0.207336407002  , 0.19559431764  , 0.170453845035  , 0.137588739935  , 0.112493251467  , 0.085666241505  , 0.07322800093  , 0.069235765986  , 0.07021059437  , 0.069244163285  , 0.061750708039  , 0.049312483172  , 0.042959205028  , 0.036837675852  , 0.031719353189  , 0.021394671603  , 0.014808132847  , 0.001833614317  , -0.003977097276  , -0.018658231311  , -0.01467240709  , -0.022897506939  , -0.029098285212  , -0.021485730832  , -0.044943649298  , -0.02684519373  , -0.029329239831  , -0.039483911622  , -0.026100292362  , -0.04040257885  , -0.032351101101  , -0.031877880401  , -0.03661129967  , -0.025668785977  , -0.033359427099  , -0.030114177235  , -0.037030323532  , -0.041144668687  , -0.035776409531  , -0.021284534631  , -0.013631538322  , -0.009674347779  , -0.016053509514  , -0.01526276696  , -0.030447537906  , -0.032576731299  , -0.036205406851  , -0.017897354038  , -0.014123776408  , 0.011912248315  , 0.040426616159  , 0.027576155785  , 0.015233629585  , 0.036407492039 );
                        u[3] = dot(x,   -0.334919737468  , -0.077957986524  , -0.022121575061  , 0.013499189945  , -0.006374989369  , -0.024707221773  , -0.029057594408  , 0.025518009776  , 0.034098748953  , 0.068379043549  , 0.011333571435  , 0.039075292919  , 0.030657138898  , 0.102545942385  , 0.142427717554  , 0.166425701831  , 0.160119776374  , 0.167054029407  , 0.155340326396  , 0.124423942112  , 0.101528385306  , 0.121046050937  , 0.111235578029  , 0.086383045502  , 0.064110310818  , 0.0070978467  , 0.048838815472  , -0.041288287525  , -0.08329743746  , -0.058221152192  , -0.188000545828  , -0.05504271665  , -0.153755965058  , -0.152802573977  , -0.138188843891  , -0.170178577021  , -0.09302875093  , -0.160919287944  , -0.116822001818  , -0.090473748845  , -0.06011726886  , -0.024972531875  , -0.037936556617  , -0.0021727358  , -0.013576464609  , -0.008719505141  , 0.007655886405  , 0.001739510889  , 0.0246888052  , 0.034844646149  , 0.036365054412  , 0.032519176378  , 0.024422948488  , 0.022813613524  , 0.030176563098  , 0.018135497848  , 0.01780487791  , 0.006410203353  , 0.001468059006  , -0.004585210381  , -0.016047425863  , -0.02382475106  , -0.016755548535  , -0.017228552324  , -0.013707021831  , -0.016774495217  , -0.019248801001  , -0.020175040602  , -0.016398068577  , -0.020049898059  , -0.022985093882  , -0.015106125346  , -0.013376945053  , -0.020776379967  , -0.013259355983  , -0.012190516288  , -0.015046308907  , -0.015095038979  , -0.012645801379  , -0.008829904156  , -0.00912226026  , -0.007788403877  , -0.007177926038  , 0.000118610628  , 0.001272244381  , 0.00521788939  , 0.001200140266  , 0.006418976115  , -0.006168779123  , 0.007505938271  , 0.000620205185  , 0.005809252854  , 0.009031463898  , 0.004573427696  , 0.009309137245  , 0.007217610763  , 0.006541346734  , 0.017901634293  , 0.008507758284  , 0.012209755588  , 0.007841824045  , 0.01344760911  , 0.00398519261  , 0.000893886002  , 0.005145022083  , 0.004362110405  , 0.00542464486  , 0.000531490967  , 0.000641877283  , 0.000962023742  , 0.00732603131  , 0.006558569335  , 0.003295947952  , 0.01073741957  , 0.012602954387  , 0.009770166748  , 0.002974103783  , 0.003234578851  , 0.005402101301  , 0.010968649893  , 0.005383085016  , 0.00995094477  , 0.005898396076  , 0.006529160319  , 0.009100448421  , 0.009720374628  , 0.01763160635  , 0.01201094765  , 0.011175949157  , 0.01201094765  , 0.01763160635  , 0.009720374628  , 0.009100448421  , 0.006529160319  , 0.005898396076  , 0.00995094477  , 0.005383085016  , 0.010968649893  , 0.005402101301  , 0.003234578851  , 0.002974103783  , 0.009770166748  , 0.012602954387  , 0.01073741957  , 0.003295947952  , 0.006558569335  , 0.00732603131  , 0.000962023742  , 0.000641877283  , 0.000531490967  , 0.00542464486  , 0.004362110405  , 0.005145022083  , 0.000893886002  , 0.00398519261  , 0.01344760911  , 0.007841824045  , 0.012209755588  , 0.008507758284  , 0.017901634293  , 0.006541346734  , 0.007217610763  , 0.009309137245  , 0.004573427696  , 0.009031463898  , 0.005809252854  , 0.000620205185  , 0.007505938271  , -0.006168779123  , 0.006418976115  , 0.001200140266  , 0.00521788939  , 0.001272244381  , 0.000118610628  , -0.007177926038  , -0.007788403877  , -0.00912226026  , -0.008829904156  , -0.012645801379  , -0.015095038979  , -0.015046308907  , -0.012190516288  , -0.013259355983  , -0.020776379967  , -0.013376945053  , -0.015106125346  , -0.022985093882  , -0.020049898059  , -0.016398068577  , -0.020175040602  , -0.019248801001  , -0.016774495217  , -0.013707021831  , -0.017228552324  , -0.016755548535  , -0.02382475106  , -0.016047425863  , -0.004585210381  , 0.001468059006  , 0.006410203353  , 0.01780487791  , 0.018135497848  , 0.030176563098  , 0.022813613524  , 0.024422948488  , 0.032519176378  , 0.036365054412  , 0.034844646149  , 0.0246888052  , 0.001739510889  , 0.007655886405  , -0.008719505141  , -0.013576464609  , -0.0021727358  , -0.037936556617  , -0.024972531875  , -0.06011726886  , -0.090473748845  , -0.116822001818  , -0.160919287944  , -0.09302875093  , -0.170178577021  , -0.138188843891  , -0.152802573977  , -0.153755965058  , -0.05504271665  , -0.188000545828  , -0.058221152192  , -0.08329743746  , -0.041288287525  , 0.048838815472  , 0.0070978467  , 0.064110310818  , 0.086383045502  , 0.111235578029  , 0.121046050937  , 0.101528385306  , 0.124423942112  , 0.155340326396  , 0.167054029407  , 0.160119776374  , 0.166425701831  , 0.142427717554  , 0.102545942385  , 0.030657138898  , 0.039075292919  , 0.011333571435  , 0.068379043549  , 0.034098748953  , 0.025518009776  , -0.029057594408  , -0.024707221773  , -0.006374989369  , 0.013499189945  , -0.022121575061  , -0.077957986524 );
                        u[4] = dot(x,   -0.272125985689  , -0.042820278104  , 0.004951661568  , 0.102685657819  , 0.080681876144  , 0.031137577056  , 0.007694750152  , 0.061183845508  , 0.01354943327  , 0.060472364407  , 0.003281104928  , 0.041449006532  , 0.019744323318  , 0.074336234209  , 0.072540313508  , 0.051387996275  , 0.003549052319  , -0.019894163727  , -0.039672832359  , -0.051766473322  , -0.088405258527  , -0.069604086398  , -0.129657065727  , -0.0931575645  , -0.077503662232  , -0.110684929817  , -0.01241105001  , -0.085586753274  , -0.042776068562  , -0.015914976552  , -0.13144329643  , 0.013454381298  , -0.05935651406  , -0.023934420553  , 0.004728861272  , -0.03370736744  , 0.04304813504  , 0.033378647042  , 0.104364991695  , 0.128966413329  , 0.177876689568  , 0.185971166225  , 0.167931623902  , 0.15648458696  , 0.156809329976  , 0.150202689865  , 0.136473262023  , 0.105785534494  , 0.104295457192  , 0.062861001431  , 0.037378379016  , 0.000776671444  , -0.030020502372  , -0.048592765088  , -0.065039120294  , -0.069322447454  , -0.064842754109  , -0.057496621573  , -0.046990293037  , -0.028827621506  , -0.044910959464  , -0.049438791633  , -0.022873563016  , -0.006596888466  , 0.002394861056  , 0.007267499477  , 0.023081259205  , 0.034010264791  , 0.050481049159  , 0.05392393455  , 0.052038786674  , 0.046438676278  , 0.03671532764  , 0.034191544187  , 0.032205503691  , 0.038255525382  , 0.028167617711  , 0.021500658098  , 0.002226793386  , 0.011956523536  , 0.004783405435  , 0.013788005395  , 0.006046740331  , 0.018189390488  , 0.012062238234  , 0.006039748608  , -0.007462364295  , -0.01116152563  , -0.004991804944  , -0.011586221281  , -0.011861122158  , -0.009836898608  , -0.005867513196  , -0.013352904081  , -0.006844948668  , -0.009870342611  , -0.014131735886  , -0.021636304126  , -0.017312854908  , -0.023501164316  , -0.018959366998  , -0.02522829494  , -0.020312834625  , -0.023518343409  , -0.023876838557  , -0.031600270279  , -0.031698544068  , -0.039003732536  , -0.037383334512  , -0.040807223678  , -0.038187217556  , -0.043818932944  , -0.04713334968  , -0.038165765893  , -0.040486409614  , -0.041099387252  , -0.033232311264  , -0.031058204408  , -0.024907989498  , -0.029212127685  , -0.033134165003  , -0.029616636544  , -0.033413060789  , -0.037051628987  , -0.028071119128  , -0.040021972158  , -0.03846722913  , -0.045803751539  , -0.042397084536  , -0.045803751539  , -0.03846722913  , -0.040021972158  , -0.028071119128  , -0.037051628987  , -0.033413060789  , -0.029616636544  , -0.033134165003  , -0.029212127685  , -0.024907989498  , -0.031058204408  , -0.033232311264  , -0.041099387252  , -0.040486409614  , -0.038165765893  , -0.04713334968  , -0.043818932944  , -0.038187217556  , -0.040807223678  , -0.037383334512  , -0.039003732536  , -0.031698544068  , -0.031600270279  , -0.023876838557  , -0.023518343409  , -0.020312834625  , -0.02522829494  , -0.018959366998  , -0.023501164316  , -0.017312854908  , -0.021636304126  , -0.014131735886  , -0.009870342611  , -0.006844948668  , -0.013352904081  , -0.005867513196  , -0.009836898608  , -0.011861122158  , -0.011586221281  , -0.004991804944  , -0.01116152563  , -0.007462364295  , 0.006039748608  , 0.012062238234  , 0.018189390488  , 0.006046740331  , 0.013788005395  , 0.004783405435  , 0.011956523536  , 0.002226793386  , 0.021500658098  , 0.028167617711  , 0.038255525382  , 0.032205503691  , 0.034191544187  , 0.03671532764  , 0.046438676278  , 0.052038786674  , 0.05392393455  , 0.050481049159  , 0.034010264791  , 0.023081259205  , 0.007267499477  , 0.002394861056  , -0.006596888466  , -0.022873563016  , -0.049438791633  , -0.044910959464  , -0.028827621506  , -0.046990293037  , -0.057496621573  , -0.064842754109  , -0.069322447454  , -0.065039120294  , -0.048592765088  , -0.030020502372  , 0.000776671444  , 0.037378379016  , 0.062861001431  , 0.104295457192  , 0.105785534494  , 0.136473262023  , 0.150202689865  , 0.156809329976  , 0.15648458696  , 0.167931623902  , 0.185971166225  , 0.177876689568  , 0.128966413329  , 0.104364991695  , 0.033378647042  , 0.04304813504  , -0.03370736744  , 0.004728861272  , -0.023934420553  , -0.05935651406  , 0.013454381298  , -0.13144329643  , -0.015914976552  , -0.042776068562  , -0.085586753274  , -0.01241105001  , -0.110684929817  , -0.077503662232  , -0.0931575645  , -0.129657065727  , -0.069604086398  , -0.088405258527  , -0.051766473322  , -0.039672832359  , -0.019894163727  , 0.003549052319  , 0.051387996275  , 0.072540313508  , 0.074336234209  , 0.019744323318  , 0.041449006532  , 0.003281104928  , 0.060472364407  , 0.01354943327  , 0.061183845508  , 0.007694750152  , 0.031137577056  , 0.080681876144  , 0.102685657819  , 0.004951661568  , -0.042820278104 );
                        memcpy(dest != NULL ? dest : x, u, sizeof(double) * 5);
                    }

                protected:
                    /**
                    * Compute dot product with varargs
                    */
                    double dot(double *x, ...) {
                        va_list w;
                        va_start(w, 256);
                        static double mean[] = {  0.011419778279 , 0.009589182349 , 0.008121788329 , 0.006217670841 , 0.005824139127 , 0.005588548779 , 0.005038334745 , 0.004455057633 , 0.004822300944 , 0.004403077183 , 0.004509965798 , 0.003877749683 , 0.004317833274 , 0.004097114021 , 0.003992976174 , 0.004091992435 , 0.004423598716 , 0.004628832634 , 0.004459344618 , 0.004429281802 , 0.004799278387 , 0.004660906027 , 0.005173508337 , 0.00494316169 , 0.004783827136 , 0.005097087425 , 0.004511795083 , 0.005112819534 , 0.0050815773 , 0.005071036367 , 0.006010483105 , 0.005023049557 , 0.005401787901 , 0.005121319514 , 0.004733955752 , 0.004960168878 , 0.004417303957 , 0.004610199088 , 0.004366341394 , 0.004259362549 , 0.004157383207 , 0.004039531321 , 0.003860205059 , 0.003729227439 , 0.003550626411 , 0.003452117317 , 0.003373330313 , 0.003276665067 , 0.003139867618 , 0.003260402596 , 0.003381120705 , 0.003588725718 , 0.003818895925 , 0.004020944815 , 0.004186774216 , 0.004297826312 , 0.004399060476 , 0.004421653326 , 0.004547951341 , 0.004723776577 , 0.005199600459 , 0.005612478816 , 0.005867554409 , 0.006108046673 , 0.006446052689 , 0.006680747192 , 0.006570851426 , 0.006612088013 , 0.006299994735 , 0.006305195179 , 0.006059566232 , 0.005844628093 , 0.005542420942 , 0.005245850025 , 0.005096962469 , 0.004858385628 , 0.004672546681 , 0.004271174431 , 0.004152330087 , 0.00383446798 , 0.003776544199 , 0.003525223057 , 0.003408455335 , 0.003219872174 , 0.00315740533 , 0.003057928703 , 0.003011269201 , 0.002913590463 , 0.002727320144 , 0.002637048747 , 0.002477776194 , 0.002387713985 , 0.002293924535 , 0.002300934492 , 0.002221308101 , 0.002246669729 , 0.002215137451 , 0.002189301303 , 0.002135760125 , 0.002175474382 , 0.002048785234 , 0.002104311708 , 0.002106762249 , 0.002129340825 , 0.002180863894 , 0.002217053758 , 0.002284739583 , 0.002280904233 , 0.002242998532 , 0.002305338911 , 0.002284100594 , 0.002284151694 , 0.002344474292 , 0.002251302877 , 0.002219121887 , 0.002160898869 , 0.001972629074 , 0.001952045972 , 0.001874871401 , 0.001792261457 , 0.00178932191 , 0.001690527163 , 0.001647478422 , 0.001628463683 , 0.00156399066 , 0.001594893757 , 0.001531778179 , 0.001495993749 , 0.001394525324 , 0.001495993749 , 0.001531778179 , 0.001594893757 , 0.00156399066 , 0.001628463683 , 0.001647478422 , 0.001690527163 , 0.00178932191 , 0.001792261457 , 0.001874871401 , 0.001952045972 , 0.001972629074 , 0.002160898869 , 0.002219121887 , 0.002251302877 , 0.002344474292 , 0.002284151694 , 0.002284100594 , 0.002305338911 , 0.002242998532 , 0.002280904233 , 0.002284739583 , 0.002217053758 , 0.002180863894 , 0.002129340825 , 0.002106762249 , 0.002104311708 , 0.002048785234 , 0.002175474382 , 0.002135760125 , 0.002189301303 , 0.002215137451 , 0.002246669729 , 0.002221308101 , 0.002300934492 , 0.002293924535 , 0.002387713985 , 0.002477776194 , 0.002637048747 , 0.002727320144 , 0.002913590463 , 0.003011269201 , 0.003057928703 , 0.00315740533 , 0.003219872174 , 0.003408455335 , 0.003525223057 , 0.003776544199 , 0.00383446798 , 0.004152330087 , 0.004271174431 , 0.004672546681 , 0.004858385628 , 0.005096962469 , 0.005245850025 , 0.005542420942 , 0.005844628093 , 0.006059566232 , 0.006305195179 , 0.006299994735 , 0.006612088013 , 0.006570851426 , 0.006680747192 , 0.006446052689 , 0.006108046673 , 0.005867554409 , 0.005612478816 , 0.005199600459 , 0.004723776577 , 0.004547951341 , 0.004421653326 , 0.004399060476 , 0.004297826312 , 0.004186774216 , 0.004020944815 , 0.003818895925 , 0.003588725718 , 0.003381120705 , 0.003260402596 , 0.003139867618 , 0.003276665067 , 0.003373330313 , 0.003452117317 , 0.003550626411 , 0.003729227439 , 0.003860205059 , 0.004039531321 , 0.004157383207 , 0.004259362549 , 0.004366341394 , 0.004610199088 , 0.004417303957 , 0.004960168878 , 0.004733955752 , 0.005121319514 , 0.005401787901 , 0.005023049557 , 0.006010483105 , 0.005071036367 , 0.0050815773 , 0.005112819534 , 0.004511795083 , 0.005097087425 , 0.004783827136 , 0.00494316169 , 0.005173508337 , 0.004660906027 , 0.004799278387 , 0.004429281802 , 0.004459344618 , 0.004628832634 , 0.004423598716 , 0.004091992435 , 0.003992976174 , 0.004097114021 , 0.004317833274 , 0.003877749683 , 0.004509965798 , 0.004403077183 , 0.004822300944 , 0.004455057633 , 0.005038334745 , 0.005588548779 , 0.005824139127 , 0.006217670841 , 0.008121788329 , 0.009589182349  };
                        double dot = 0.0;

                        for (uint16_t i = 0; i < 256; i++) {
                            dot += (x[i] - mean[i]) * va_arg(w, double);
                        }

                        return dot;
                    }
                };
            }
        }
    }