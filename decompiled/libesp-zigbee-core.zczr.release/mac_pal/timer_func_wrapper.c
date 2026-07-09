/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> mac_pal.o -> timer_func_wrapper
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Removing unreachable block (ram,0x00010174) */
/* WARNING: Removing unreachable block (ram,0x00010180) */

void timer_func_wrapper(void)

{
  byte bVar1;
  byte bVar2;
  char cVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  
  iVar5 = DAT_0001057c;
  if ((char)s_mac_pal_ctx != '\x03') {
    if ((char)s_mac_pal_ctx != '\x04') {
      return;
    }
    if ((DAT_00010590 & 1) != 0) {
      return;
    }
    micro_timer_stop(&s_mac_pal_ctx);
    s_mac_pal_ctx._1_1_ = 0;
    if (((DAT_00010590 & 2) != 0) || (*(byte *)(iVar5 + 0x10) <= DAT_0001057a)) {
      set_state(2);
      mac_pal_callback_tx_done(iVar5,0,0x1e9);
      return;
    }
    DAT_0001057a = DAT_0001057a + 1;
    bVar1 = *(byte *)(DAT_0001057c + 0x13);
    bVar2 = *(byte *)(DAT_0001057c + 0x12);
    cVar3 = *(char *)(DAT_0001057c + 0x11);
    set_state(3);
    if (((DAT_00010590 & 4) == 0) && (cVar3 != '\0')) {
      uVar6 = (uint)bVar2;
      if ((uint)bVar1 < (uint)bVar2) {
        uVar6 = (uint)bVar1;
      }
      iVar5 = random_noncrypto_range_u32(0,1 << (uVar6 & 0x1f));
      if ((DAT_0001057b & 1) == 0) {
        ezb_plat_radio_sleep();
      }
      else {
        ezb_plat_radio_receive(*(undefined1 *)(DAT_0001057c + 5));
      }
      micro_timer_start(&s_mac_pal_ctx,iVar5 * 0x140);
      return;
    }
  }
  iVar5 = DAT_0001057c;
  if ((char)s_mac_pal_ctx != '\x03') {
    return;
  }
  iVar4 = ezb_plat_radio_receive(*(undefined1 *)(DAT_0001057c + 5));
  if (iVar4 == 0) goto _L0;
  do {
    __assert_func(0,0,0,0);
_L0:
    set_state(4);
    iVar4 = ezb_plat_radio_transmit(iVar5);
  } while (iVar4 != 0);
  return;
}

