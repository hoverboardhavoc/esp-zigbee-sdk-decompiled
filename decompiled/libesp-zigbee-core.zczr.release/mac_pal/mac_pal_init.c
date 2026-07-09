/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
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
  DAT_0001057c = ezb_plat_radio_get_transmit_buffer();
  pcVar2 = pcVar1;
  if (DAT_0001057c != 0) goto _L0;
  do {
    __assert_func(0,0,0,0);
    pcVar2 = pcVar1;
_L0:
    pcVar1 = pcVar2 + 0x578;
    micro_timer_init(&s_mac_pal_ctx,timer_func_wrapper,0);
    iVar4 = ezb_plat_radio_is_enabled();
  } while ((iVar4 != 0) && (iVar4 = mac_pal_disable(), iVar4 != 0));
  uVar3 = ezb_plat_radio_get_capabilities();
  *pcVar1 = (code)0x0;
  *(undefined2 *)(pcVar2 + 0x590) = uVar3;
  return;
}

