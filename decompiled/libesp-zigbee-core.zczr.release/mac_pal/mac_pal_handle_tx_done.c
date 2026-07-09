/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> mac_pal.o -> mac_pal_handle_tx_done
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void mac_pal_handle_tx_done(int param_1,undefined4 param_2,int param_3)

{
  byte bVar1;
  byte bVar2;
  char cVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  
  micro_timer_stop(&s_mac_pal_ctx);
  if ((((DAT_00010590 & 4) == 0) && (param_3 == 0x1e1)) &&
     (s_mac_pal_ctx._1_1_ < *(byte *)(param_1 + 0x11))) {
    s_mac_pal_ctx._1_1_ = s_mac_pal_ctx._1_1_ + 1;
  }
  else {
    s_mac_pal_ctx._1_1_ = 0;
    if ((((DAT_00010590 & 2) != 0) || (param_3 == 0)) || (*(byte *)(param_1 + 0x10) <= DAT_0001057a)
       ) {
      set_state(2);
      mac_pal_callback_tx_done(param_1,param_2,param_3);
      return;
    }
    DAT_0001057a = DAT_0001057a + 1;
  }
  bVar1 = *(byte *)(DAT_0001057c + 0x13);
  bVar2 = *(byte *)(DAT_0001057c + 0x12);
  cVar3 = *(char *)(DAT_0001057c + 0x11);
  uVar4 = (uint)s_mac_pal_ctx._1_1_;
  set_state(3);
  iVar6 = DAT_0001057c;
  if (((DAT_00010590 & 4) == 0) && (cVar3 != '\0')) {
    uVar7 = uVar4 + bVar1 & 0xff;
    uVar4 = (uint)bVar2;
    if (uVar7 < bVar2) {
      uVar4 = uVar7;
    }
    iVar6 = random_noncrypto_range_u32(0,1 << (uVar4 & 0x1f));
    if ((DAT_0001057b & 1) == 0) {
      ezb_plat_radio_sleep();
    }
    else {
      ezb_plat_radio_receive(*(undefined1 *)(DAT_0001057c + 5));
    }
    micro_timer_start(&s_mac_pal_ctx,iVar6 * 0x140);
    return;
  }
  if ((char)s_mac_pal_ctx != '\x03') {
    return;
  }
  iVar5 = ezb_plat_radio_receive(*(undefined1 *)(DAT_0001057c + 5));
  if (iVar5 == 0) goto _L0;
  do {
    __assert_func(0,0,0,0);
_L0:
    set_state(4);
    iVar5 = ezb_plat_radio_transmit(iVar6);
  } while (iVar5 != 0);
  return;
}

