/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.release -> mac_pal.o -> mac_pal_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void mac_pal_init(void)

{
  code *pcVar1;
  code *pcVar2;
  undefined2 uVar3;
  int iVar4;
  ezb_err_t eVar5;
  
  pcVar1 = set_state;
  memset(&s_mac_pal_ctx,0,0x1c);
  s_mac_pal_ctx.tx_frame = (ezb_radio_frame_t *)ezb_plat_radio_get_transmit_buffer();
  pcVar2 = pcVar1;
  if (s_mac_pal_ctx.tx_frame != (ezb_radio_frame_t *)0x0) goto _L0;
  do {
    __assert_func(0,0,0,0);
    pcVar2 = pcVar1;
_L0:
    pcVar1 = pcVar2 + 0x578;
    micro_timer_init(&s_mac_pal_ctx,timer_func_wrapper,0);
    iVar4 = ezb_plat_radio_is_enabled();
  } while ((iVar4 != 0) && (eVar5 = mac_pal_disable(), eVar5 != 0));
  uVar3 = ezb_plat_radio_get_capabilities();
  *pcVar1 = (code)0x0;
  *(undefined2 *)(pcVar2 + 0x590) = uVar3;
  return;
}

