/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-core.zczr.release -> mac_pal.o -> mac_pal_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void mac_pal_init(void)

{
  code *pcVar1;
  code *pcVar2;
  undefined2 uVar3;
  int iVar4;
  
  pcVar1 = set_state;
  memset(&s_mac_pal_ctx,0,0x1c);
  DAT_00010630 = ezb_plat_radio_get_transmit_buffer();
  pcVar2 = pcVar1;
  if (DAT_00010630 != 0) goto _L0;
  do {
    __assert_func(0,0,0,0);
    pcVar2 = pcVar1;
_L0:
    pcVar1 = pcVar2 + 0x62c;
    micro_timer_init(&s_mac_pal_ctx,timer_func_wrapper,0);
    iVar4 = ezb_plat_radio_is_enabled();
  } while ((iVar4 != 0) && (iVar4 = mac_pal_disable(), iVar4 != 0));
  uVar3 = ezb_plat_radio_get_capabilities();
  *pcVar1 = (code)0x0;
  *(undefined2 *)(pcVar2 + 0x644) = uVar3;
  return;
}

