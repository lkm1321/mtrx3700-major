###########################################################################################
# The contents of this file are subject to the Pumpkin Salvo
# License (the "License").  You may not use this file except
# in compliance with the License. You may obtain a copy of
# the License at http://www.pumpkininc.com, or from
# warranty@pumpkininc.com.
# 
# Software distributed under the License is distributed on an
# "AS IS" basis, WITHOUT WARRANTY OF ANY KIND, either express
# or implied. See the License for specific language governing
# the warranty and the rights and limitations under the
# License.
# 
# The Original Code is Salvo - the Cooperative, Multitasking
# RTOS. Copyright (C) 1995-2001 Pumpkin, Inc. and its
# Licensor(s). All Rights Reserved.
# 
# $Source: C:\\RCS\\d\\salvo\\src\\targets.mk,v $
# $Author: aek $
# $Revision: 3.36 $
# $Date: 2003-10-16 19:58:04-07 $
# 
#   For use with \salvo\src\Makefile
# 
#   Runs under Cygwin's bash shell, and presumably others, too. Created and tested
# under GNU make 3.79.1.
# 


###########################################################################################
#
#   targets: libraries for HI-TECH PICC and Microchip PIC12-series PICmicros.
#   Since these PICmicros don't have interrupts, no variants are necessary.
#
HT_PICC_p2xx_FAMILIES  = p200 p210 p211 p212 p222

HT_PICC_p2xx_LIBRARIES = $(HT_PICC_p200_LIBRARIES) $(HT_PICC_p210_LIBRARIES) \
                         $(HT_PICC_p211_LIBRARIES) $(HT_PICC_p212_LIBRARIES) \
                         $(HT_PICC_p222_LIBRARIES)
                               
HT_PICC_p200_LIBRARIES = sfp200a-.lib \
                         sfp200d-.lib \
                         sfp200e-.lib \
                         sfp200m-.lib \
                         sfp200t-.lib \
                         slp200a-.lib \
                         slp200d-.lib \
                         slp200e-.lib \
                         slp200m-.lib \
                         slp200t-.lib

HT_PICC_p210_LIBRARIES = sfp210a-.lib \
                         sfp210d-.lib \
                         sfp210e-.lib \
                         sfp210m-.lib \
                         sfp210t-.lib \
                         slp210a-.lib \
                         slp210d-.lib \
                         slp210e-.lib \
                         slp210m-.lib \
                         slp210t-.lib

HT_PICC_p211_LIBRARIES = sfp211a-.lib \
                         sfp211d-.lib \
                         sfp211e-.lib \
                         sfp211m-.lib \
                         sfp211t-.lib \
                         slp211a-.lib \
                         slp211d-.lib \
                         slp211e-.lib \
                         slp211m-.lib \
                         slp211t-.lib

HT_PICC_p212_LIBRARIES = sfp212a-.lib \
                         sfp212d-.lib \
                         sfp212e-.lib \
                         sfp212m-.lib \
                         sfp212t-.lib \
                         slp212a-.lib \
                         slp212d-.lib \
                         slp212e-.lib \
                         slp212m-.lib \
                         slp212t-.lib

HT_PICC_p222_LIBRARIES = sfp222a-.lib \
                         sfp222d-.lib \
                         sfp222e-.lib \
                         sfp222m-.lib \
                         sfp222t-.lib \
                         slp222a-.lib \
                         slp222d-.lib \
                         slp222e-.lib \
                         slp222m-.lib \
                         slp222t-.lib

                
###########################################################################################
#
#   targets: libraries for HI-TECH PICC and Microchip PIC16-series PICmicros
#
HT_PICC_p4xx_FAMILIES  = p401 p40a p40b p40c p411 p412 p41b p41c p42c p926

HT_PICC_p4xx_LIBRARIES = $(HT_PICC_p401_LIBRARIES) $(HT_PICC_p40a_LIBRARIES) \
                         $(HT_PICC_p40b_LIBRARIES) $(HT_PICC_p40c_LIBRARIES) \
                         $(HT_PICC_p411_LIBRARIES) $(HT_PICC_p412_LIBRARIES) \
                         $(HT_PICC_p41b_LIBRARIES) $(HT_PICC_p41c_LIBRARIES) \
                         $(HT_PICC_p42c_LIBRARIES) $(HT_PICC_p926_LIBRARIES) 

HT_PICC_p401_LIBRARIES = sfp401aa.lib sfp401ab.lib sfp401af.lib \
                         sfp401da.lib sfp401db.lib sfp401df.lib \
                         sfp401ea.lib sfp401eb.lib sfp401ef.lib \
                         sfp401ma.lib sfp401mb.lib sfp401mf.lib \
                         sfp401ta.lib sfp401tb.lib sfp401tf.lib \
                         slp401aa.lib slp401ab.lib slp401af.lib \
                         slp401da.lib slp401db.lib slp401df.lib \
                         slp401ea.lib slp401eb.lib slp401ef.lib \
                         slp401ma.lib slp401mb.lib slp401mf.lib \
                         slp401ta.lib slp401tb.lib slp401tf.lib
               
HT_PICC_p40a_LIBRARIES = sfp40aaa.lib sfp40aab.lib sfp40aaf.lib \
                         sfp40ada.lib sfp40adb.lib sfp40adf.lib \
                         sfp40aea.lib sfp40aeb.lib sfp40aef.lib \
                         sfp40ama.lib sfp40amb.lib sfp40amf.lib \
                         sfp40ata.lib sfp40atb.lib sfp40atf.lib \
                         slp40aaa.lib slp40aab.lib slp40aaf.lib \
                         slp40ada.lib slp40adb.lib slp40adf.lib \
                         slp40aea.lib slp40aeb.lib slp40aef.lib \
                         slp40ama.lib slp40amb.lib slp40amf.lib \
                         slp40ata.lib slp40atb.lib slp40atf.lib
               
HT_PICC_p40b_LIBRARIES = sfp40baa.lib sfp40bab.lib sfp40baf.lib \
                         sfp40bda.lib sfp40bdb.lib sfp40bdf.lib \
                         sfp40bea.lib sfp40beb.lib sfp40bef.lib \
                         sfp40bma.lib sfp40bmb.lib sfp40bmf.lib \
                         sfp40bta.lib sfp40btb.lib sfp40btf.lib \
                         slp40baa.lib slp40bab.lib slp40baf.lib \
                         slp40bda.lib slp40bdb.lib slp40bdf.lib \
                         slp40bea.lib slp40beb.lib slp40bef.lib \
                         slp40bma.lib slp40bmb.lib slp40bmf.lib \
                         slp40bta.lib slp40btb.lib slp40btf.lib

HT_PICC_p40c_LIBRARIES = sfp40caa.lib sfp40cab.lib sfp40caf.lib \
                         sfp40cda.lib sfp40cdb.lib sfp40cdf.lib \
                         sfp40cea.lib sfp40ceb.lib sfp40cef.lib \
                         sfp40cma.lib sfp40cmb.lib sfp40cmf.lib \
                         sfp40cta.lib sfp40ctb.lib sfp40ctf.lib \
                         slp40caa.lib slp40cab.lib slp40caf.lib \
                         slp40cda.lib slp40cdb.lib slp40cdf.lib \
                         slp40cea.lib slp40ceb.lib slp40cef.lib \
                         slp40cma.lib slp40cmb.lib slp40cmf.lib \
                         slp40cta.lib slp40ctb.lib slp40ctf.lib

HT_PICC_p411_LIBRARIES = sfp411aa.lib sfp411ab.lib sfp411af.lib \
                         sfp411da.lib sfp411db.lib sfp411df.lib \
                         sfp411ea.lib sfp411eb.lib sfp411ef.lib \
                         sfp411ma.lib sfp411mb.lib sfp411mf.lib \
                         sfp411ta.lib sfp411tb.lib sfp411tf.lib \
                         slp411aa.lib slp411ab.lib slp411af.lib \
                         slp411da.lib slp411db.lib slp411df.lib \
                         slp411ea.lib slp411eb.lib slp411ef.lib \
                         slp411ma.lib slp411mb.lib slp411mf.lib \
                         slp411ta.lib slp411tb.lib slp411tf.lib

HT_PICC_p412_LIBRARIES = sfp412aa.lib sfp412ab.lib sfp412af.lib \
                         sfp412da.lib sfp412db.lib sfp412df.lib \
                         sfp412ea.lib sfp412eb.lib sfp412ef.lib \
                         sfp412ma.lib sfp412mb.lib sfp412mf.lib \
                         sfp412ta.lib sfp412tb.lib sfp412tf.lib \
                         slp412aa.lib slp412ab.lib slp412af.lib \
                         slp412da.lib slp412db.lib slp412df.lib \
                         slp412ea.lib slp412eb.lib slp412ef.lib \
                         slp412ma.lib slp412mb.lib slp412mf.lib \
                         slp412ta.lib slp412tb.lib slp412tf.lib

HT_PICC_p41b_LIBRARIES = sfp41baa.lib sfp41bab.lib sfp41baf.lib \
                         sfp41bda.lib sfp41bdb.lib sfp41bdf.lib \
                         sfp41bea.lib sfp41beb.lib sfp41bef.lib \
                         sfp41bma.lib sfp41bmb.lib sfp41bmf.lib \
                         sfp41bta.lib sfp41btb.lib sfp41btf.lib \
                         slp41baa.lib slp41bab.lib slp41baf.lib \
                         slp41bda.lib slp41bdb.lib slp41bdf.lib \
                         slp41bea.lib slp41beb.lib slp41bef.lib \
                         slp41bma.lib slp41bmb.lib slp41bmf.lib \
                         slp41bta.lib slp41btb.lib slp41btf.lib

HT_PICC_p41c_LIBRARIES = sfp41caa.lib sfp41cab.lib sfp41caf.lib \
                         sfp41cda.lib sfp41cdb.lib sfp41cdf.lib \
                         sfp41cea.lib sfp41ceb.lib sfp41cef.lib \
                         sfp41cma.lib sfp41cmb.lib sfp41cmf.lib \
                         sfp41cta.lib sfp41ctb.lib sfp41ctf.lib \
                         slp41caa.lib slp41cab.lib slp41caf.lib \
                         slp41cda.lib slp41cdb.lib slp41cdf.lib \
                         slp41cea.lib slp41ceb.lib slp41cef.lib \
                         slp41cma.lib slp41cmb.lib slp41cmf.lib \
                         slp41cta.lib slp41ctb.lib slp41ctf.lib
                         
HT_PICC_p42c_LIBRARIES = sfp42caa.lib sfp42cab.lib sfp42caf.lib \
                         sfp42cda.lib sfp42cdb.lib sfp42cdf.lib \
                         sfp42cea.lib sfp42ceb.lib sfp42cef.lib \
                         sfp42cma.lib sfp42cmb.lib sfp42cmf.lib \
                         sfp42cta.lib sfp42ctb.lib sfp42ctf.lib \
                         slp42caa.lib slp42cab.lib slp42caf.lib \
                         slp42cda.lib slp42cdb.lib slp42cdf.lib \
                         slp42cea.lib slp42ceb.lib slp42cef.lib \
                         slp42cma.lib slp42cmb.lib slp42cmf.lib \
                         slp42cta.lib slp42ctb.lib slp42ctf.lib

HT_PICC_p432_LIBRARIES = sfp432aa.lib sfp432ab.lib sfp432af.lib \
                         sfp432da.lib sfp432db.lib sfp432df.lib \
                         sfp432ea.lib sfp432eb.lib sfp432ef.lib \
                         sfp432ma.lib sfp432mb.lib sfp432mf.lib \
                         sfp432ta.lib sfp432tb.lib sfp432tf.lib \
                         slp432aa.lib slp432ab.lib slp432af.lib \
                         slp432da.lib slp432db.lib slp432df.lib \
                         slp432ea.lib slp432eb.lib slp432ef.lib \
                         slp432ma.lib slp432mb.lib slp432mf.lib \
                         slp432ta.lib slp432tb.lib slp432tf.lib

HT_PICC_p43c_LIBRARIES = sfp43caa.lib sfp43cab.lib sfp43caf.lib \
                         sfp43cda.lib sfp43cdb.lib sfp43cdf.lib \
                         sfp43cea.lib sfp43ceb.lib sfp43cef.lib \
                         sfp43cma.lib sfp43cmb.lib sfp43cmf.lib \
                         sfp43cta.lib sfp43ctb.lib sfp43ctf.lib \
                         slp43caa.lib slp43cab.lib slp43caf.lib \
                         slp43cda.lib slp43cdb.lib slp43cdf.lib \
                         slp43cea.lib slp43ceb.lib slp43cef.lib \
                         slp43cma.lib slp43cmb.lib slp43cmf.lib \
                         slp43cta.lib slp43ctb.lib slp43ctf.lib


HT_PICC_p926_LIBRARIES = sfp926aa.lib sfp926ab.lib sfp926af.lib \
                         sfp926da.lib sfp926db.lib sfp926df.lib \
                         sfp926ea.lib sfp926eb.lib sfp926ef.lib \
                         sfp926ma.lib sfp926mb.lib sfp926mf.lib \
                         sfp926ta.lib sfp926tb.lib sfp926tf.lib \
                         slp926aa.lib slp926ab.lib slp926af.lib \
                         slp926da.lib slp926db.lib slp926df.lib \
                         slp926ea.lib slp926eb.lib slp926ef.lib \
                         slp926ma.lib slp926mb.lib slp926mf.lib \
                         slp926ta.lib slp926tb.lib slp926tf.lib


###########################################################################################
#
#   targets: libraries for HI-TECH PICC and Microchip PIC17-series PICmicros
#
HT_PICC_p7xx_FAMILIES  = p700 p704 p710 p714

HT_PICC_p7xx_LIBRARIES = $(HT_PICC_p700_LIBRARIES) $(HT_PICC_p704_LIBRARIES) \
                         $(HT_PICC_p710_LIBRARIES) $(HT_PICC_p714_LIBRARIES)

HT_PICC_p700_LIBRARIES = sfp700aa.lib sfp700ab.lib sfp700af.lib \
                         sfp700da.lib sfp700db.lib sfp700df.lib \
                         sfp700ea.lib sfp700eb.lib sfp700ef.lib \
                         sfp700ma.lib sfp700mb.lib sfp700mf.lib \
                         sfp700ta.lib sfp700tb.lib sfp700tf.lib \
                         slp700aa.lib slp700ab.lib slp700af.lib \
                         slp700da.lib slp700db.lib slp700df.lib \
                         slp700ea.lib slp700eb.lib slp700ef.lib \
                         slp700ma.lib slp700mb.lib slp700mf.lib \
                         slp700ta.lib slp700tb.lib slp700tf.lib
               
HT_PICC_p704_LIBRARIES = sfp704aa.lib sfp704ab.lib sfp704af.lib \
                         sfp704da.lib sfp704db.lib sfp704df.lib \
                         sfp704ea.lib sfp704eb.lib sfp704ef.lib \
                         sfp704ma.lib sfp704mb.lib sfp704mf.lib \
                         sfp704ta.lib sfp704tb.lib sfp704tf.lib \
                         slp704aa.lib slp704ab.lib slp704af.lib \
                         slp704da.lib slp704db.lib slp704df.lib \
                         slp704ea.lib slp704eb.lib slp704ef.lib \
                         slp704ma.lib slp704mb.lib slp704mf.lib \
                         slp704ta.lib slp704tb.lib slp704tf.lib
               
HT_PICC_p710_LIBRARIES = sfp710aa.lib sfp710ab.lib sfp710af.lib \
                         sfp710da.lib sfp710db.lib sfp710df.lib \
                         sfp710ea.lib sfp710eb.lib sfp710ef.lib \
                         sfp710ma.lib sfp710mb.lib sfp710mf.lib \
                         sfp710ta.lib sfp710tb.lib sfp710tf.lib \
                         slp710aa.lib slp710ab.lib slp710af.lib \
                         slp710da.lib slp710db.lib slp710df.lib \
                         slp710ea.lib slp710eb.lib slp710ef.lib \
                         slp710ma.lib slp710mb.lib slp710mf.lib \
                         slp710ta.lib slp710tb.lib slp710tf.lib

HT_PICC_p714_LIBRARIES = sfp714aa.lib sfp714ab.lib sfp714af.lib \
                         sfp714da.lib sfp714db.lib sfp714df.lib \
                         sfp714ea.lib sfp714eb.lib sfp714ef.lib \
                         sfp714ma.lib sfp714mb.lib sfp714mf.lib \
                         sfp714ta.lib sfp714tb.lib sfp714tf.lib \
                         slp714aa.lib slp714ab.lib slp714af.lib \
                         slp714da.lib slp714db.lib slp714df.lib \
                         slp714ea.lib slp714eb.lib slp714ef.lib \
                         slp714ma.lib slp714mb.lib slp714mf.lib \
                         slp714ta.lib slp714tb.lib slp714tf.lib


###########################################################################################
#
#   targets: libraries for HI-TECH PICC-18 and Microchip PIC18-series PICmicros
#
HT_PICC_p8xx_FAMILIES  = p80s p80l p81s p81l p82s p82l p83s p83l p86s p86l p87s p87l

HT_PICC_p8xx_LIBRARIES = $(HT_PICC_p80s_LIBRARIES) $(HT_PICC_p80l_LIBRARIES) \
                         $(HT_PICC_p81s_LIBRARIES) $(HT_PICC_p81l_LIBRARIES) \
                         $(HT_PICC_p82s_LIBRARIES) $(HT_PICC_p82l_LIBRARIES) \
                         $(HT_PICC_p83s_LIBRARIES) $(HT_PICC_p83l_LIBRARIES) \
                         $(HT_PICC_p86s_LIBRARIES) $(HT_PICC_p86l_LIBRARIES) \
                         $(HT_PICC_p87s_LIBRARIES) $(HT_PICC_p87l_LIBRARIES)                          						

HT_PICC_p80s_LIBRARIES = sfp80saa.lib sfp80sab.lib sfp80saf.lib \
                         sfp80sda.lib sfp80sdb.lib sfp80sdf.lib \
                         sfp80sea.lib sfp80seb.lib sfp80sef.lib \
                         sfp80sma.lib sfp80smb.lib sfp80smf.lib \
                         sfp80sta.lib sfp80stb.lib sfp80stf.lib \
                         slp80saa.lib slp80sab.lib slp80saf.lib \
                         slp80sda.lib slp80sdb.lib slp80sdf.lib \
                         slp80sea.lib slp80seb.lib slp80sef.lib \
                         slp80sma.lib slp80smb.lib slp80smf.lib \
                         slp80sta.lib slp80stb.lib slp80stf.lib

HT_PICC_p80l_LIBRARIES = sfp80laa.lib sfp80lab.lib sfp80laf.lib \
                         sfp80lda.lib sfp80ldb.lib sfp80ldf.lib \
                         sfp80lea.lib sfp80leb.lib sfp80lef.lib \
                         sfp80lma.lib sfp80lmb.lib sfp80lmf.lib \
                         sfp80lta.lib sfp80ltb.lib sfp80ltf.lib \
                         slp80laa.lib slp80lab.lib slp80laf.lib \
                         slp80lda.lib slp80ldb.lib slp80ldf.lib \
                         slp80lea.lib slp80leb.lib slp80lef.lib \
                         slp80lma.lib slp80lmb.lib slp80lmf.lib \
                         slp80lta.lib slp80ltb.lib slp80ltf.lib

HT_PICC_p81s_LIBRARIES = sfp81saa.lib sfp81sab.lib sfp81saf.lib \
                         sfp81sda.lib sfp81sdb.lib sfp81sdf.lib \
                         sfp81sea.lib sfp81seb.lib sfp81sef.lib \
                         sfp81sma.lib sfp81smb.lib sfp81smf.lib \
                         sfp81sta.lib sfp81stb.lib sfp81stf.lib \
                         slp81saa.lib slp81sab.lib slp81saf.lib \
                         slp81sda.lib slp81sdb.lib slp81sdf.lib \
                         slp81sea.lib slp81seb.lib slp81sef.lib \
                         slp81sma.lib slp81smb.lib slp81smf.lib \
                         slp81sta.lib slp81stb.lib slp81stf.lib

HT_PICC_p81l_LIBRARIES = sfp81laa.lib sfp81lab.lib sfp81laf.lib \
                         sfp81lda.lib sfp81ldb.lib sfp81ldf.lib \
                         sfp81lea.lib sfp81leb.lib sfp81lef.lib \
                         sfp81lma.lib sfp81lmb.lib sfp81lmf.lib \
                         sfp81lta.lib sfp81ltb.lib sfp81ltf.lib \
                         slp81laa.lib slp81lab.lib slp81laf.lib \
                         slp81lda.lib slp81ldb.lib slp81ldf.lib \
                         slp81lea.lib slp81leb.lib slp81lef.lib \
                         slp81lma.lib slp81lmb.lib slp81lmf.lib \
                         slp81lta.lib slp81ltb.lib slp81ltf.lib

HT_PICC_p82s_LIBRARIES = sfp82saa.lib sfp82sab.lib sfp82saf.lib \
                         sfp82sda.lib sfp82sdb.lib sfp82sdf.lib \
                         sfp82sea.lib sfp82seb.lib sfp82sef.lib \
                         sfp82sma.lib sfp82smb.lib sfp82smf.lib \
                         sfp82sta.lib sfp82stb.lib sfp82stf.lib \
                         slp82saa.lib slp82sab.lib slp82saf.lib \
                         slp82sda.lib slp82sdb.lib slp82sdf.lib \
                         slp82sea.lib slp82seb.lib slp82sef.lib \
                         slp82sma.lib slp82smb.lib slp82smf.lib \
                         slp82sta.lib slp82stb.lib slp82stf.lib

HT_PICC_p82l_LIBRARIES = sfp82laa.lib sfp82lab.lib sfp82laf.lib \
                         sfp82lda.lib sfp82ldb.lib sfp82ldf.lib \
                         sfp82lea.lib sfp82leb.lib sfp82lef.lib \
                         sfp82lma.lib sfp82lmb.lib sfp82lmf.lib \
                         sfp82lta.lib sfp82ltb.lib sfp82ltf.lib \
                         slp82laa.lib slp82lab.lib slp82laf.lib \
                         slp82lda.lib slp82ldb.lib slp82ldf.lib \
                         slp82lea.lib slp82leb.lib slp82lef.lib \
                         slp82lma.lib slp82lmb.lib slp82lmf.lib \
                         slp82lta.lib slp82ltb.lib slp82ltf.lib

HT_PICC_p83s_LIBRARIES = sfp83saa.lib sfp83sab.lib sfp83saf.lib \
                         sfp83sda.lib sfp83sdb.lib sfp83sdf.lib \
                         sfp83sea.lib sfp83seb.lib sfp83sef.lib \
                         sfp83sma.lib sfp83smb.lib sfp83smf.lib \
                         sfp83sta.lib sfp83stb.lib sfp83stf.lib \
                         slp83saa.lib slp83sab.lib slp83saf.lib \
                         slp83sda.lib slp83sdb.lib slp83sdf.lib \
                         slp83sea.lib slp83seb.lib slp83sef.lib \
                         slp83sma.lib slp83smb.lib slp83smf.lib \
                         slp83sta.lib slp83stb.lib slp83stf.lib

HT_PICC_p83l_LIBRARIES = sfp83laa.lib sfp83lab.lib sfp83laf.lib \
                         sfp83lda.lib sfp83ldb.lib sfp83ldf.lib \
                         sfp83lea.lib sfp83leb.lib sfp83lef.lib \
                         sfp83lma.lib sfp83lmb.lib sfp83lmf.lib \
                         sfp83lta.lib sfp83ltb.lib sfp83ltf.lib \
                         slp83laa.lib slp83lab.lib slp83laf.lib \
                         slp83lda.lib slp83ldb.lib slp83ldf.lib \
                         slp83lea.lib slp83leb.lib slp83lef.lib \
                         slp83lma.lib slp83lmb.lib slp83lmf.lib \
                         slp83lta.lib slp83ltb.lib slp83ltf.lib

HT_PICC_p86s_LIBRARIES = sfp86saa.lib sfp86sab.lib sfp86saf.lib \
                         sfp86sda.lib sfp86sdb.lib sfp86sdf.lib \
                         sfp86sea.lib sfp86seb.lib sfp86sef.lib \
                         sfp86sma.lib sfp86smb.lib sfp86smf.lib \
                         sfp86sta.lib sfp86stb.lib sfp86stf.lib \
                         slp86saa.lib slp86sab.lib slp86saf.lib \
                         slp86sda.lib slp86sdb.lib slp86sdf.lib \
                         slp86sea.lib slp86seb.lib slp86sef.lib \
                         slp86sma.lib slp86smb.lib slp86smf.lib \
                         slp86sta.lib slp86stb.lib slp86stf.lib

HT_PICC_p86l_LIBRARIES = sfp86laa.lib sfp86lab.lib sfp86laf.lib \
                         sfp86lda.lib sfp86ldb.lib sfp86ldf.lib \
                         sfp86lea.lib sfp86leb.lib sfp86lef.lib \
                         sfp86lma.lib sfp86lmb.lib sfp86lmf.lib \
                         sfp86lta.lib sfp86ltb.lib sfp86ltf.lib \
                         slp86laa.lib slp86lab.lib slp86laf.lib \
                         slp86lda.lib slp86ldb.lib slp86ldf.lib \
                         slp86lea.lib slp86leb.lib slp86lef.lib \
                         slp86lma.lib slp86lmb.lib slp86lmf.lib \
                         slp86lta.lib slp86ltb.lib slp86ltf.lib

HT_PICC_p87s_LIBRARIES = sfp87saa.lib sfp87sab.lib sfp87saf.lib \
                         sfp87sda.lib sfp87sdb.lib sfp87sdf.lib \
                         sfp87sea.lib sfp87seb.lib sfp87sef.lib \
                         sfp87sma.lib sfp87smb.lib sfp87smf.lib \
                         sfp87sta.lib sfp87stb.lib sfp87stf.lib \
                         slp87saa.lib slp87sab.lib slp87saf.lib \
                         slp87sda.lib slp87sdb.lib slp87sdf.lib \
                         slp87sea.lib slp87seb.lib slp87sef.lib \
                         slp87sma.lib slp87smb.lib slp87smf.lib \
                         slp87sta.lib slp87stb.lib slp87stf.lib

HT_PICC_p87l_LIBRARIES = sfp87laa.lib sfp87lab.lib sfp87laf.lib \
                         sfp87lda.lib sfp87ldb.lib sfp87ldf.lib \
                         sfp87lea.lib sfp87leb.lib sfp87lef.lib \
                         sfp87lma.lib sfp87lmb.lib sfp87lmf.lib \
                         sfp87lta.lib sfp87ltb.lib sfp87ltf.lib \
                         slp87laa.lib slp87lab.lib slp87laf.lib \
                         slp87lda.lib slp87ldb.lib slp87ldf.lib \
                         slp87lea.lib slp87leb.lib slp87lef.lib \
                         slp87lma.lib slp87lmb.lib slp87lmf.lib \
                         slp87lta.lib slp87ltb.lib slp87ltf.lib

###########################################################################################
#
#   targets: libraries for Microchip MPLAB-C18 and Microchip PIC18-series PICmicros
#
MPLAB_C18_FAMILIES       = c18

MPLAB_C18_LIBRARIES      = $(MPLAB_C18_c18_LIBRARIES)

MPLAB_C18_c18_LIBRARIES  = sfc18lfa.lib slc18lfa.lib \
                           sfc18lfd.lib slc18lfd.lib \
                           sfc18lfe.lib slc18lfe.lib \
                           sfc18lfm.lib slc18lfm.lib \
                           sfc18lft.lib slc18lft.lib \
                           sfc18lna.lib slc18lna.lib \
                           sfc18lnd.lib slc18lnd.lib \
                           sfc18lne.lib slc18lne.lib \
                           sfc18lnm.lib slc18lnm.lib \
                           sfc18lnt.lib slc18lnt.lib \
                           sfc18sfa.lib slc18sfa.lib \
                           sfc18sfd.lib slc18sfd.lib \
                           sfc18sfe.lib slc18sfe.lib \
                           sfc18sfm.lib slc18sfm.lib \
                           sfc18sft.lib slc18sft.lib \
                           sfc18sna.lib slc18sna.lib \
                           sfc18snd.lib slc18snd.lib \
                           sfc18sne.lib slc18sne.lib \
                           sfc18snm.lib slc18snm.lib \
                           sfc18snt.lib slc18snt.lib 


###########################################################################################
#
#   targets: libraries for IAR PIC18CXXX and Microchip PIC18-series PICmicros
#
IAR_PIC18_FAMILIES         = iar18

IAR_PIC18_LIBRARIES        = $(IAR_PIC18_iar18_LIBRARIES)

IAR_PIC18_iar18_LIBRARIES  = sfiar18-slfa.r49 sliar18-slfa.r49 sliar18islfa.r49 \
                             sfiar18-slfd.r49 sliar18-slfd.r49 sliar18islfd.r49 \
                             sfiar18-slfe.r49 sliar18-slfe.r49 sliar18islfe.r49 \
                             sfiar18-slfm.r49 sliar18-slfm.r49 sliar18islfm.r49 \
                             sfiar18-slft.r49 sliar18-slft.r49 sliar18islft.r49 \
                             sfiar18-slna.r49 sliar18-slna.r49 sliar18islna.r49 \
                             sfiar18-slnd.r49 sliar18-slnd.r49 sliar18islnd.r49 \
                             sfiar18-slne.r49 sliar18-slne.r49 sliar18islne.r49 \
                             sfiar18-slnm.r49 sliar18-slnm.r49 sliar18islnm.r49 \
                             sfiar18-slnt.r49 sliar18-slnt.r49 sliar18islnt.r49


###########################################################################################
#
#   targets: libraries for HI-TECH V8C and VAutomation V8-uRISC core
#
HT_V8C_cv8_FAMILIES  = cv8

HT_V8C_cv8_LIBRARIES = sfcv8aa.lib sfcv8ab.lib sfcv8af.lib \
                       sfcv8da.lib sfcv8db.lib sfcv8df.lib \
                       sfcv8ea.lib sfcv8eb.lib sfcv8ef.lib \
                       sfcv8ma.lib sfcv8mb.lib sfcv8mf.lib \
                       sfcv8ta.lib sfcv8tb.lib sfcv8tf.lib \
                       slcv8aa.lib slcv8ab.lib slcv8af.lib \
                       slcv8da.lib slcv8db.lib slcv8df.lib \
                       slcv8ea.lib slcv8eb.lib slcv8ef.lib \
                       slcv8ma.lib slcv8mb.lib slcv8mf.lib \
                       slcv8ta.lib slcv8tb.lib slcv8tf.lib
                       
                       
###########################################################################################
#
#   targets: libraries for GNU C compiler (x86 target). Follows standard naming convention
# for libraries.
#
GCC_x86_FAMILIES     = gccx86

GCC_x86_LIBRARIES    = libsfgccx86a-.a \
                       libsfgccx86d-.a \
                       libsfgccx86e-.a \
                       libsfgccx86m-.a \
                       libsfgccx86t-.a \
                       libslgccx86a-.a \
                       libslgccx86d-.a \
                       libslgccx86e-.a \
                       libslgccx86m-.a \
                       libslgccx86t-.a 
                       
###########################################################################################
#
#   targets: libraries for GNU C compiler (6811 target). Follows standard naming convention
# for libraries.
#
GCC_6811_FAMILIES    = gcc6811

GCC_6811_LIBRARIES   = libsfgcc6811a-.a \
                       libsfgcc6811d-.a \
                       libsfgcc6811e-.a \
                       libsfgcc6811m-.a \
                       libsfgcc6811t-.a \
                       libslgcc6811a-.a \
                       libslgcc6811d-.a \
                       libslgcc6811e-.a \
                       libslgcc6811m-.a \
                       libslgcc6811t-.a 
 
                       
###########################################################################################
#
#   targets: libraries for GNU GCCAVR C compiler (AVR targets). tiny and SE are not supported.
#
GCC_AVR_FAMILIES     = gccavr

GCC_AVR_LIBRARIES    = libsfgccavr-a.a \
                       libsfgccavr-d.a \
                       libsfgccavr-e.a \
                       libsfgccavr-m.a \
                       libsfgccavr-t.a \
                       libslgccavr-a.a \
                       libslgccavr-d.a \
                       libslgccavr-e.a \
                       libslgccavr-m.a \
                       libslgccavr-t.a \
                       libslgccavria.a \
                       libslgccavrid.a \
                       libslgccavrie.a \
                       libslgccavrim.a \
                       libslgccavrit.a 					   


###########################################################################################
#
#   targets: libraries for ImageCraft ICC11 C compiler (M68HC11 target).
#
ICC_11_FAMILIES      = icc11

ICC_11_LIBRARIES     = libsficc11-a.a \
                       libsficc11-d.a \
                       libsficc11-e.a \
                       libsficc11-m.a \
                       libsficc11-t.a \
                       libslicc11-a.a \
                       libslicc11-d.a \
                       libslicc11-e.a \
                       libslicc11-m.a \
                       libslicc11-s.a \
                       libslicc11-t.a \
                       libslicc11-y.a \
                       libslicc11ia.a \
                       libslicc11id.a \
                       libslicc11ie.a \
                       libslicc11im.a \
                       libslicc11it.a 
                       
###########################################################################################
#
#   targets: libraries for ImageCraft ICC430 C compiler (MSP430 target).
#
ICC_430_FAMILIES     = icc430

ICC_430_LIBRARIES    = libsficc430-a.a \
                       libsficc430-d.a \
                       libsficc430-e.a \
                       libsficc430-m.a \
                       libsficc430-t.a \
                       libslicc430-a.a \
                       libslicc430-d.a \
                       libslicc430-e.a \
                       libslicc430-m.a \
                       libslicc430-s.a \
                       libslicc430-t.a \
                       libslicc430-y.a \
                       libslicc430ia.a \
                       libslicc430id.a \
                       libslicc430ie.a \
                       libslicc430im.a \
                       libslicc430it.a 
                       
###########################################################################################
#
#   targets: libraries for ImageCraft ICCAVR C compiler (AVR and MegaAVR targets).
#
ICC_AVR_FAMILIES     = iccavr

ICC_AVR_LIBRARIES    = libsficcavr-a.a \
                       libsficcavr-d.a \
                       libsficcavr-e.a \
                       libsficcavr-m.a \
                       libsficcavr-t.a \
                       libsliccavr-a.a \
                       libsliccavr-d.a \
                       libsliccavr-e.a \
                       libsliccavr-m.a \
                       libsliccavr-s.a \
                       libsliccavr-t.a \
                       libsliccavr-y.a \
                       libsliccavria.a \
                       libsliccavrid.a \
                       libsliccavrie.a \
                       libsliccavrim.a \
                       libsliccavrit.a 
                       
ICC_ATMEGA_FAMILIES  = iccatmega

ICC_ATMEGA_LIBRARIES = libsficcatmega-a.a \
                       libsficcatmega-d.a \
                       libsficcatmega-e.a \
                       libsficcatmega-m.a \
                       libsficcatmega-t.a \
                       libsliccatmega-a.a \
                       libsliccatmega-d.a \
                       libsliccatmega-e.a \
                       libsliccatmega-m.a \
                       libsliccatmega-s.a \
                       libsliccatmega-t.a \
                       libsliccatmega-y.a \
                       libsliccatmegaia.a \
                       libsliccatmegaid.a \
                       libsliccatmegaie.a \
                       libsliccatmegaim.a \
                       libsliccatmegait.a 
                       
###########################################################################################
#
#   targets: libraries for Archelon / Quadravox AQ430 C compiler (TI MSP430 target). 
#
AQ_430_FAMILIES      = aq430

AQ_430_LIBRARIES     = sfaq430-a.lib \
                       sfaq430-d.lib \
                       sfaq430-e.lib \
                       sfaq430-m.lib \
                       sfaq430-t.lib \
                       slaq430-a.lib \
                       slaq430-d.lib \
                       slaq430-e.lib \
                       slaq430-m.lib \
                       slaq430-s.lib \
                       slaq430-t.lib \
                       slaq430-y.lib \
                       slaq430ia.lib \
                       slaq430id.lib \
                       slaq430ie.lib \
                       slaq430im.lib \
                       slaq430it.lib 
                       
###########################################################################################
#
#   targets: libraries for CrossWorks for MSP430 C compiler (TI MSP430 target). 
#
CS_430_FAMILIES      = cs430

CS_430_LIBRARIES     = libsfcs430-a.hza \
                       libsfcs430-d.hza \
                       libsfcs430-e.hza \
                       libsfcs430-m.hza \
                       libsfcs430-t.hza \
                       libslcs430-a.hza \
                       libslcs430-d.hza \
                       libslcs430-e.hza \
                       libslcs430-m.hza \
                       libslcs430-s.hza \
                       libslcs430-t.hza \
                       libslcs430-y.hza \
                       libslcs430ia.hza \
                       libslcs430id.hza \
                       libslcs430ie.hza \
                       libslcs430im.hza \
                       libslcs430it.hza 
                       
###########################################################################################
#
#   targets: libraries for IAR 430 C compiler (TI MSP430 target). 
#
#   NOTE: Salvo library names are identical for v1.x and v2.x versions of the compilers.
#         Files are kept in separate directories, salvo/lib/iar430-v1 and salvo/lib/iar430-v2.
#
IAR_430_V1_FAMILIES  = iar430-v1

IAR_430_V2_FAMILIES  = iar430-v2

IAR_430_LIBRARIES    = sfiar430-a.r43 \
                       sfiar430-d.r43 \
                       sfiar430-e.r43 \
                       sfiar430-m.r43 \
                       sfiar430-t.r43 \
                       sliar430-a.r43 \
                       sliar430-d.r43 \
                       sliar430-e.r43 \
                       sliar430-m.r43 \
                       sliar430-t.r43 \
                       sliar430ia.r43 \
                       sliar430id.r43 \
                       sliar430ie.r43 \
                       sliar430im.r43 \
                       sliar430it.r43 
                       
###########################################################################################
#
#   targets: libraries for ZDS II compiler (Zilog Z8 Encore target). 
#
ZLG_EZ8_FAMILIES     = ez8

ZLG_EZ8_LIBRARIES    = sfez8-sa.lib \
                       sfez8-sd.lib \
                       sfez8-se.lib \
                       sfez8-sm.lib \
                       sfez8-st.lib \
                       slez8-sa.lib \
                       slez8-sd.lib \
                       slez8-se.lib \
                       slez8-sm.lib \
                       slez8-st.lib 
                       
###########################################################################################
#
#   targets: libraries for TI Code Composer / Code COmposer Studio (TMS320C2000 family). 
#
#
TI_C2400_FAMILIES    = tic24x

TI_C2800_FAMILIES    = tic28x

TI_C2400_LIBRARIES   = $(TI_C24x_LIBRARIES)
                       
TI_C2800_LIBRARIES   = $(TI_C28x_LIBRARIES)
                       
TI_C24x_LIBRARIES    = sftic24x-a.lib \
                       sftic24x-d.lib \
                       sftic24x-e.lib \
                       sftic24x-m.lib \
                       sftic24x-t.lib \
                       sltic24x-a.lib \
                       sltic24x-d.lib \
                       sltic24x-e.lib \
                       sltic24x-m.lib \
                       sltic24x-t.lib \
                       sltic24xia.lib \
                       sltic24xid.lib \
                       sltic24xie.lib \
                       sltic24xim.lib \
                       sltic24xit.lib 
                       
TI_C28x_LIBRARIES    = sftic28xl-a.lib \
                       sftic28xl-d.lib \
                       sftic28xl-e.lib \
                       sftic28xl-m.lib \
                       sftic28xl-t.lib \
                       sltic28xl-a.lib \
                       sltic28xl-d.lib \
                       sltic28xl-e.lib \
                       sltic28xl-m.lib \
                       sltic28xl-t.lib \
                       sltic28xlia.lib \
                       sltic28xlid.lib \
                       sltic28xlie.lib \
                       sltic28xlim.lib \
                       sltic28xlit.lib 
                       
                       
###########################################################################################
#
#   targets: libraries for Keil C51 and Cx51 compilers (8051 target). Follows standard naming convention
# for libraries. C/L/S = Compact/Large/Small memory model, D/I/X = data/idata/xdata memory
# types for Salvo variables.
#
KEIL_C51_FAMILIES     = c51

KEIL_C51_LIBRARIES    = $(KEIL_C51_CD_LIBRARIES) $(KEIL_C51_CI_LIBRARIES) \
                        $(KEIL_C51_CX_LIBRARIES) $(KEIL_C51_LD_LIBRARIES) \
                        $(KEIL_C51_LI_LIBRARIES) $(KEIL_C51_LX_LIBRARIES) \
                        $(KEIL_C51_SD_LIBRARIES) $(KEIL_C51_SI_LIBRARIES) \
                        $(KEIL_C51_SX_LIBRARIES)

KEIL_C51_CD_LIBRARIES = sfc51cdaa.lib sfc51cdab.lib sfc51cdae.lib \
                        sfc51cdda.lib sfc51cddb.lib sfc51cdde.lib \
                        sfc51cdea.lib sfc51cdeb.lib sfc51cdee.lib \
                        sfc51cdma.lib sfc51cdmb.lib sfc51cdme.lib \
                        sfc51cdta.lib sfc51cdtb.lib sfc51cdte.lib \
                        slc51cdaa.lib slc51cdab.lib slc51cdae.lib \
                        slc51cdda.lib slc51cddb.lib slc51cdde.lib \
                        slc51cdea.lib slc51cdeb.lib slc51cdee.lib \
                        slc51cdma.lib slc51cdmb.lib slc51cdme.lib \
                        slc51cdta.lib slc51cdtb.lib slc51cdte.lib 
                       
KEIL_C51_CI_LIBRARIES = sfc51ciaa.lib sfc51ciab.lib sfc51ciae.lib \
                        sfc51cida.lib sfc51cidb.lib sfc51cide.lib \
                        sfc51ciea.lib sfc51cieb.lib sfc51ciee.lib \
                        sfc51cima.lib sfc51cimb.lib sfc51cime.lib \
                        sfc51cita.lib sfc51citb.lib sfc51cite.lib \
                        slc51ciaa.lib slc51ciab.lib slc51ciae.lib \
                        slc51cida.lib slc51cidb.lib slc51cide.lib \
                        slc51ciea.lib slc51cieb.lib slc51ciee.lib \
                        slc51cima.lib slc51cimb.lib slc51cime.lib \
                        slc51cita.lib slc51citb.lib slc51cite.lib 
                       
KEIL_C51_CX_LIBRARIES = sfc51cxaa.lib sfc51cxab.lib sfc51cxae.lib \
                        sfc51cxda.lib sfc51cxdb.lib sfc51cxde.lib \
                        sfc51cxea.lib sfc51cxeb.lib sfc51cxee.lib \
                        sfc51cxma.lib sfc51cxmb.lib sfc51cxme.lib \
                        sfc51cxta.lib sfc51cxtb.lib sfc51cxte.lib \
                        slc51cxaa.lib slc51cxab.lib slc51cxae.lib \
                        slc51cxda.lib slc51cxdb.lib slc51cxde.lib \
                        slc51cxea.lib slc51cxeb.lib slc51cxee.lib \
                        slc51cxma.lib slc51cxmb.lib slc51cxme.lib \
                        slc51cxta.lib slc51cxtb.lib slc51cxte.lib 
                       
KEIL_C51_LD_LIBRARIES = sfc51ldaa.lib sfc51ldab.lib sfc51ldae.lib \
                        sfc51ldda.lib sfc51lddb.lib sfc51ldde.lib \
                        sfc51ldea.lib sfc51ldeb.lib sfc51ldee.lib \
                        sfc51ldma.lib sfc51ldmb.lib sfc51ldme.lib \
                        sfc51ldta.lib sfc51ldtb.lib sfc51ldte.lib \
                        slc51ldaa.lib slc51ldab.lib slc51ldae.lib \
                        slc51ldda.lib slc51lddb.lib slc51ldde.lib \
                        slc51ldea.lib slc51ldeb.lib slc51ldee.lib \
                        slc51ldma.lib slc51ldmb.lib slc51ldme.lib \
                        slc51ldta.lib slc51ldtb.lib slc51ldte.lib 
                       
KEIL_C51_LI_LIBRARIES = sfc51liaa.lib sfc51liab.lib sfc51liae.lib \
                        sfc51lida.lib sfc51lidb.lib sfc51lide.lib \
                        sfc51liea.lib sfc51lieb.lib sfc51liee.lib \
                        sfc51lima.lib sfc51limb.lib sfc51lime.lib \
                        sfc51lita.lib sfc51litb.lib sfc51lite.lib \
                        slc51liaa.lib slc51liab.lib slc51liae.lib \
                        slc51lida.lib slc51lidb.lib slc51lide.lib \
                        slc51liea.lib slc51lieb.lib slc51liee.lib \
                        slc51lima.lib slc51limb.lib slc51lime.lib \
                        slc51lita.lib slc51litb.lib slc51lite.lib 
                       
KEIL_C51_LX_LIBRARIES = sfc51lxaa.lib sfc51lxab.lib sfc51lxae.lib \
                        sfc51lxda.lib sfc51lxdb.lib sfc51lxde.lib \
                        sfc51lxea.lib sfc51lxeb.lib sfc51lxee.lib \
                        sfc51lxma.lib sfc51lxmb.lib sfc51lxme.lib \
                        sfc51lxta.lib sfc51lxtb.lib sfc51lxte.lib \
                        slc51lxaa.lib slc51lxab.lib slc51lxae.lib \
                        slc51lxda.lib slc51lxdb.lib slc51lxde.lib \
                        slc51lxea.lib slc51lxeb.lib slc51lxee.lib \
                        slc51lxma.lib slc51lxmb.lib slc51lxme.lib \
                        slc51lxta.lib slc51lxtb.lib slc51lxte.lib 
                       
KEIL_C51_SD_LIBRARIES = sfc51sdaa.lib sfc51sdab.lib sfc51sdae.lib \
                        sfc51sdda.lib sfc51sddb.lib sfc51sdde.lib \
                        sfc51sdea.lib sfc51sdeb.lib sfc51sdee.lib \
                        sfc51sdma.lib sfc51sdmb.lib sfc51sdme.lib \
                        sfc51sdta.lib sfc51sdtb.lib sfc51sdte.lib \
                        slc51sdaa.lib slc51sdab.lib slc51sdae.lib \
                        slc51sdda.lib slc51sddb.lib slc51sdde.lib \
                        slc51sdea.lib slc51sdeb.lib slc51sdee.lib \
                        slc51sdma.lib slc51sdmb.lib slc51sdme.lib \
                        slc51sdta.lib slc51sdtb.lib slc51sdte.lib 
                       
KEIL_C51_SI_LIBRARIES = sfc51siaa.lib sfc51siab.lib sfc51siae.lib \
                        sfc51sida.lib sfc51sidb.lib sfc51side.lib \
                        sfc51siea.lib sfc51sieb.lib sfc51siee.lib \
                        sfc51sima.lib sfc51simb.lib sfc51sime.lib \
                        sfc51sita.lib sfc51sitb.lib sfc51site.lib \
                        slc51siaa.lib slc51siab.lib slc51siae.lib \
                        slc51sida.lib slc51sidb.lib slc51side.lib \
                        slc51siea.lib slc51sieb.lib slc51siee.lib \
                        slc51sima.lib slc51simb.lib slc51sime.lib \
                        slc51sita.lib slc51sitb.lib slc51site.lib 
                       
KEIL_C51_SX_LIBRARIES = sfc51sxaa.lib sfc51sxab.lib sfc51sxae.lib \
                        sfc51sxda.lib sfc51sxdb.lib sfc51sxde.lib \
                        sfc51sxea.lib sfc51sxeb.lib sfc51sxee.lib \
                        sfc51sxma.lib sfc51sxmb.lib sfc51sxme.lib \
                        sfc51sxta.lib sfc51sxtb.lib sfc51sxte.lib \
                        slc51sxaa.lib slc51sxab.lib slc51sxae.lib \
                        slc51sxda.lib slc51sxdb.lib slc51sxde.lib \
                        slc51sxea.lib slc51sxeb.lib slc51sxee.lib \
                        slc51sxma.lib slc51sxmb.lib slc51sxme.lib \
                        slc51sxta.lib slc51sxtb.lib slc51sxte.lib 
                       

KEIL_Cx51_FAMILIES     = cx51

KEIL_Cx51_LIBRARIES    = $(KEIL_Cx51_CD_LIBRARIES) $(KEIL_Cx51_CI_LIBRARIES) \
                        $(KEIL_Cx51_CX_LIBRARIES) $(KEIL_Cx51_LD_LIBRARIES) \
                        $(KEIL_Cx51_LI_LIBRARIES) $(KEIL_Cx51_LX_LIBRARIES) \
                        $(KEIL_Cx51_SD_LIBRARIES) $(KEIL_Cx51_SI_LIBRARIES) \
                        $(KEIL_Cx51_SX_LIBRARIES)

KEIL_Cx51_CD_LIBRARIES = sfcx51cdaa.lib sfcx51cdab.lib sfcx51cdae.lib \
                        sfcx51cdda.lib sfcx51cddb.lib sfcx51cdde.lib \
                        sfcx51cdea.lib sfcx51cdeb.lib sfcx51cdee.lib \
                        sfcx51cdma.lib sfcx51cdmb.lib sfcx51cdme.lib \
                        sfcx51cdta.lib sfcx51cdtb.lib sfcx51cdte.lib \
                        slcx51cdaa.lib slcx51cdab.lib slcx51cdae.lib \
                        slcx51cdda.lib slcx51cddb.lib slcx51cdde.lib \
                        slcx51cdea.lib slcx51cdeb.lib slcx51cdee.lib \
                        slcx51cdma.lib slcx51cdmb.lib slcx51cdme.lib \
                        slcx51cdta.lib slcx51cdtb.lib slcx51cdte.lib 
                       
KEIL_Cx51_CI_LIBRARIES = sfcx51ciaa.lib sfcx51ciab.lib sfcx51ciae.lib \
                        sfcx51cida.lib sfcx51cidb.lib sfcx51cide.lib \
                        sfcx51ciea.lib sfcx51cieb.lib sfcx51ciee.lib \
                        sfcx51cima.lib sfcx51cimb.lib sfcx51cime.lib \
                        sfcx51cita.lib sfcx51citb.lib sfcx51cite.lib \
                        slcx51ciaa.lib slcx51ciab.lib slcx51ciae.lib \
                        slcx51cida.lib slcx51cidb.lib slcx51cide.lib \
                        slcx51ciea.lib slcx51cieb.lib slcx51ciee.lib \
                        slcx51cima.lib slcx51cimb.lib slcx51cime.lib \
                        slcx51cita.lib slcx51citb.lib slcx51cite.lib 
                       
KEIL_Cx51_CX_LIBRARIES = sfcx51cxaa.lib sfcx51cxab.lib sfcx51cxae.lib \
                        sfcx51cxda.lib sfcx51cxdb.lib sfcx51cxde.lib \
                        sfcx51cxea.lib sfcx51cxeb.lib sfcx51cxee.lib \
                        sfcx51cxma.lib sfcx51cxmb.lib sfcx51cxme.lib \
                        sfcx51cxta.lib sfcx51cxtb.lib sfcx51cxte.lib \
                        slcx51cxaa.lib slcx51cxab.lib slcx51cxae.lib \
                        slcx51cxda.lib slcx51cxdb.lib slcx51cxde.lib \
                        slcx51cxea.lib slcx51cxeb.lib slcx51cxee.lib \
                        slcx51cxma.lib slcx51cxmb.lib slcx51cxme.lib \
                        slcx51cxta.lib slcx51cxtb.lib slcx51cxte.lib 
                       
KEIL_Cx51_LD_LIBRARIES = sfcx51ldaa.lib sfcx51ldab.lib sfcx51ldae.lib \
                        sfcx51ldda.lib sfcx51lddb.lib sfcx51ldde.lib \
                        sfcx51ldea.lib sfcx51ldeb.lib sfcx51ldee.lib \
                        sfcx51ldma.lib sfcx51ldmb.lib sfcx51ldme.lib \
                        sfcx51ldta.lib sfcx51ldtb.lib sfcx51ldte.lib \
                        slcx51ldaa.lib slcx51ldab.lib slcx51ldae.lib \
                        slcx51ldda.lib slcx51lddb.lib slcx51ldde.lib \
                        slcx51ldea.lib slcx51ldeb.lib slcx51ldee.lib \
                        slcx51ldma.lib slcx51ldmb.lib slcx51ldme.lib \
                        slcx51ldta.lib slcx51ldtb.lib slcx51ldte.lib 
                       
KEIL_Cx51_LI_LIBRARIES = sfcx51liaa.lib sfcx51liab.lib sfcx51liae.lib \
                        sfcx51lida.lib sfcx51lidb.lib sfcx51lide.lib \
                        sfcx51liea.lib sfcx51lieb.lib sfcx51liee.lib \
                        sfcx51lima.lib sfcx51limb.lib sfcx51lime.lib \
                        sfcx51lita.lib sfcx51litb.lib sfcx51lite.lib \
                        slcx51liaa.lib slcx51liab.lib slcx51liae.lib \
                        slcx51lida.lib slcx51lidb.lib slcx51lide.lib \
                        slcx51liea.lib slcx51lieb.lib slcx51liee.lib \
                        slcx51lima.lib slcx51limb.lib slcx51lime.lib \
                        slcx51lita.lib slcx51litb.lib slcx51lite.lib 
                       
KEIL_Cx51_LX_LIBRARIES = sfcx51lxaa.lib sfcx51lxab.lib sfcx51lxae.lib \
                        sfcx51lxda.lib sfcx51lxdb.lib sfcx51lxde.lib \
                        sfcx51lxea.lib sfcx51lxeb.lib sfcx51lxee.lib \
                        sfcx51lxma.lib sfcx51lxmb.lib sfcx51lxme.lib \
                        sfcx51lxta.lib sfcx51lxtb.lib sfcx51lxte.lib \
                        slcx51lxaa.lib slcx51lxab.lib slcx51lxae.lib \
                        slcx51lxda.lib slcx51lxdb.lib slcx51lxde.lib \
                        slcx51lxea.lib slcx51lxeb.lib slcx51lxee.lib \
                        slcx51lxma.lib slcx51lxmb.lib slcx51lxme.lib \
                        slcx51lxta.lib slcx51lxtb.lib slcx51lxte.lib 
                       
KEIL_Cx51_SD_LIBRARIES = sfcx51sdaa.lib sfcx51sdab.lib sfcx51sdae.lib \
                        sfcx51sdda.lib sfcx51sddb.lib sfcx51sdde.lib \
                        sfcx51sdea.lib sfcx51sdeb.lib sfcx51sdee.lib \
                        sfcx51sdma.lib sfcx51sdmb.lib sfcx51sdme.lib \
                        sfcx51sdta.lib sfcx51sdtb.lib sfcx51sdte.lib \
                        slcx51sdaa.lib slcx51sdab.lib slcx51sdae.lib \
                        slcx51sdda.lib slcx51sddb.lib slcx51sdde.lib \
                        slcx51sdea.lib slcx51sdeb.lib slcx51sdee.lib \
                        slcx51sdma.lib slcx51sdmb.lib slcx51sdme.lib \
                        slcx51sdta.lib slcx51sdtb.lib slcx51sdte.lib 
                       
KEIL_Cx51_SI_LIBRARIES = sfcx51siaa.lib sfcx51siab.lib sfcx51siae.lib \
                        sfcx51sida.lib sfcx51sidb.lib sfcx51side.lib \
                        sfcx51siea.lib sfcx51sieb.lib sfcx51siee.lib \
                        sfcx51sima.lib sfcx51simb.lib sfcx51sime.lib \
                        sfcx51sita.lib sfcx51sitb.lib sfcx51site.lib \
                        slcx51siaa.lib slcx51siab.lib slcx51siae.lib \
                        slcx51sida.lib slcx51sidb.lib slcx51side.lib \
                        slcx51siea.lib slcx51sieb.lib slcx51siee.lib \
                        slcx51sima.lib slcx51simb.lib slcx51sime.lib \
                        slcx51sita.lib slcx51sitb.lib slcx51site.lib 
                       
KEIL_Cx51_SX_LIBRARIES = sfcx51sxaa.lib sfcx51sxab.lib sfcx51sxae.lib \
                        sfcx51sxda.lib sfcx51sxdb.lib sfcx51sxde.lib \
                        sfcx51sxea.lib sfcx51sxeb.lib sfcx51sxee.lib \
                        sfcx51sxma.lib sfcx51sxmb.lib sfcx51sxme.lib \
                        sfcx51sxta.lib sfcx51sxtb.lib sfcx51sxte.lib \
                        slcx51sxaa.lib slcx51sxab.lib slcx51sxae.lib \
                        slcx51sxda.lib slcx51sxdb.lib slcx51sxde.lib \
                        slcx51sxea.lib slcx51sxeb.lib slcx51sxee.lib \
                        slcx51sxma.lib slcx51sxmb.lib slcx51sxme.lib \
                        slcx51sxta.lib slcx51sxtb.lib slcx51sxte.lib 
                       

###########################################################################################
#
#   targets: libraries for HI-TECH C51 compiler (8051 target). Follows standard naming convention
# for libraries. L/M/S = Large/Medium/Small memory model, D/I/X = data/idata/xdata memory
# types for Salvo variables.
#
HT_C51_FAMILIES       = 51

HT_C51_LIBRARIES      = $(HT_C51_LX_LIBRARIES) $(HT_C51_MX_LIBRARIES) \
                        $(HT_C51_SX_LIBRARIES)

#HT_C51_LIBRARIES      = $(HT_C51_LD_LIBRARIES) $(HT_C51_LI_LIBRARIES) \
#                        $(HT_C51_LX_LIBRARIES) $(HT_C51_MD_LIBRARIES) \
#                        $(HT_C51_MI_LIBRARIES) $(HT_C51_MX_LIBRARIES) \
#                        $(HT_C51_SD_LIBRARIES) $(HT_C51_SI_LIBRARIES) \
#                        $(HT_C51_SX_LIBRARIES)

HT_C51_LD_LIBRARIES   = sf51lda-.lib \
                        sf51ldd-.lib \
                        sf51lde-.lib \
                        sf51ldm-.lib \
                        sf51ldt-.lib \
                        sl51lda-.lib \
                        sl51ldd-.lib \
                        sl51lde-.lib \
                        sl51ldm-.lib \
                        sl51ldt-.lib  
                       
HT_C51_LI_LIBRARIES   = sf51lia-.lib \
                        sf51lid-.lib \
                        sf51lie-.lib \
                        sf51lim-.lib \
                        sf51lit-.lib \
                        sl51lia-.lib \
                        sl51lid-.lib \
                        sl51lie-.lib \
                        sl51lim-.lib \
                        sl51lit-.lib  
                       
HT_C51_LX_LIBRARIES   = sf51lxa-.lib \
                        sf51lxd-.lib \
                        sf51lxe-.lib \
                        sf51lxm-.lib \
                        sf51lxt-.lib \
                        sl51lxa-.lib \
                        sl51lxd-.lib \
                        sl51lxe-.lib \
                        sl51lxm-.lib \
                        sl51lxt-.lib  
                       
HT_C51_MD_LIBRARIES   = sf51mda-.lib \
                        sf51mdd-.lib \
                        sf51mde-.lib \
                        sf51mdm-.lib \
                        sf51mdt-.lib \
                        sl51mda-.lib \
                        sl51mdd-.lib \
                        sl51mde-.lib \
                        sl51mdm-.lib \
                        sl51mdt-.lib  
                       
HT_C51_MI_LIBRARIES   = sf51mia-.lib \
                        sf51mid-.lib \
                        sf51mie-.lib \
                        sf51mim-.lib \
                        sf51mit-.lib \
                        sl51mia-.lib \
                        sl51mid-.lib \
                        sl51mie-.lib \
                        sl51mim-.lib \
                        sl51mit-.lib 
                       
HT_C51_MX_LIBRARIES   = sf51mxa-.lib \
                        sf51mxd-.lib \
                        sf51mxe-.lib \
                        sf51mxm-.lib \
                        sf51mxt-.lib \
                        sl51mxa-.lib \
                        sl51mxd-.lib \
                        sl51mxe-.lib \
                        sl51mxm-.lib \
                        sl51mxt-.lib  
                       
HT_C51_SD_LIBRARIES   = sf51sda-.lib \
                        sf51sdd-.lib \
                        sf51sde-.lib \
                        sf51sdm-.lib \
                        sf51sdt-.lib \
                        sl51sda-.lib \
                        sl51sdd-.lib \
                        sl51sde-.lib \
                        sl51sdm-.lib \
                        sl51sdt-.lib  
                       
HT_C51_SI_LIBRARIES   = sf51sia-.lib \
                        sf51sid-.lib \
                        sf51sie-.lib \
                        sf51sim-.lib \
                        sf51sit-.lib \
                        sl51sia-.lib \
                        sl51sid-.lib \
                        sl51sie-.lib \
                        sl51sim-.lib \
                        sl51sit-.lib  
                       
HT_C51_SX_LIBRARIES   = sf51sxa-.lib \
                        sf51sxd-.lib \
                        sf51sxe-.lib \
                        sf51sxm-.lib \
                        sf51sxt-.lib \
                        sl51sxa-.lib \
                        sl51sxd-.lib \
                        sl51sxe-.lib \
                        sl51sxm-.lib \
                        sl51sxt-.lib  
                       
