/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-core.zczr.release -> mac_pal.o -> start_csma
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void start_csma(void)

{
  byte bVar1;
  byte bVar2;
  char cVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  
  bVar1 = *(byte *)(DAT_00010630 + 0x13);
  bVar2 = *(byte *)(DAT_00010630 + 0x12);
  cVar3 = *(char *)(DAT_00010630 + 0x11);
  uVar4 = (uint)DAT_0001062d;
  set_state(3);
  iVar6 = DAT_00010630;
  if (((DAT_00010644 & 4) == 0) && (cVar3 != '\0')) {
    uVar7 = uVar4 + bVar1 & 0xff;
    uVar4 = (uint)bVar2;
    if (uVar7 < bVar2) {
      uVar4 = uVar7;
    }
    iVar6 = random_noncrypto_range_u32(0,1 << (uVar4 & 0x1f));
    if ((DAT_00010646 & 1) == 0) {
      ezb_plat_radio_sleep();
    }
    else {
      ezb_plat_radio_receive(*(undefined1 *)(DAT_00010630 + 5));
    }
    micro_timer_start(&s_mac_pal_ctx,iVar6 * 0x140);
    return;
  }
  if (s_mac_pal_ctx != '\x03') {
    return;
  }
  iVar5 = ezb_plat_radio_receive(*(undefined1 *)(DAT_00010630 + 5));
  if (iVar5 == 0) goto _L0;
  do {
    __assert_func(0,0,0,0);
_L0:
    set_state(4);
    iVar5 = ezb_plat_radio_transmit(iVar6);
  } while (iVar5 != 0);
  return;
}

