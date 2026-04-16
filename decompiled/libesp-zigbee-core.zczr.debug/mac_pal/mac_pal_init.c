/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> mac_pal.o -> mac_pal_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void mac_pal_init(void)

{
  int iVar1;
  ezb_err_t eVar2;
  
  s_mac_pal_ctx.state = '\0';
  s_mac_pal_ctx.csma_nb = '\0';
  s_mac_pal_ctx.tx_retries = '\0';
  s_mac_pal_ctx._3_1_ = 0;
  s_mac_pal_ctx.tx_frame = (ezb_radio_frame_t *)0x0;
  s_mac_pal_ctx.op_timer.next = (timer_base *)0x0;
  s_mac_pal_ctx.op_timer.timer_func = (timer_func_t)0x0;
  s_mac_pal_ctx.op_timer.user_ctx = (void *)0x0;
  s_mac_pal_ctx.op_timer.fire_time.val = 0;
  s_mac_pal_ctx.tx_frame = (ezb_radio_frame_t *)ezb_plat_radio_get_transmit_buffer();
  if (s_mac_pal_ctx.tx_frame == (ezb_radio_frame_t *)0x0) {
    __assert_func("//build/esp-zigbee/src/core/mac/mac_pal.c",0x109,"mac_pal_init",
                  "s_mac_pal_ctx.tx_frame != ((void *)0)");
  }
  else {
    micro_timer_init(&s_mac_pal_ctx,timer_func_wrapper,0);
    iVar1 = ezb_plat_radio_is_enabled();
    if (iVar1 == 0) goto _L0;
  }
  eVar2 = mac_pal_disable();
  if (eVar2 != 0) {
    __assert_func("//build/esp-zigbee/src/core/mac/mac_pal.c",0x10e,"mac_pal_init",
                  "(mac_pal_disable()) == 0");
    iVar1 = ezb_plat_radio_is_enabled();
    if ((iVar1 != 0) && (eVar2 = mac_pal_disable(), eVar2 != 0)) {
      __assert_func("//build/esp-zigbee/src/core/mac/mac_pal.c",0x116,"mac_pal_deinit",
                    "(mac_pal_disable()) == 0");
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
    s_mac_pal_ctx.tx_frame = (ezb_radio_frame_t *)0x0;
    return;
  }
_L0:
  s_mac_pal_ctx._0_4_ = s_mac_pal_ctx._0_4_ & 0xffffff00;
  return;
}

