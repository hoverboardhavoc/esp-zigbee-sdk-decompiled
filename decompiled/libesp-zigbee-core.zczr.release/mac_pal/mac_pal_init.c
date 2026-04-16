/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
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
  int iVar2;
  ezb_err_t eVar3;
  
  pcVar1 = set_state;
  memset(&s_mac_pal_ctx,0,0x18);
  s_mac_pal_ctx.tx_frame = (ezb_radio_frame_t *)ezb_plat_radio_get_transmit_buffer();
  if (s_mac_pal_ctx.tx_frame != (ezb_radio_frame_t *)0x0) goto _L0;
  do {
    __assert_func(0,0,0,0);
_L0:
    pcVar1 = pcVar1 + 0x3f0;
    micro_timer_init(&s_mac_pal_ctx,timer_func_wrapper,0);
    iVar2 = ezb_plat_radio_is_enabled();
  } while ((iVar2 != 0) && (eVar3 = mac_pal_disable(), eVar3 != 0));
  *pcVar1 = (code)0x0;
  return;
}

