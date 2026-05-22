/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
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
  uint16_t uVar1;
  int iVar2;
  ezb_err_t eVar3;
  
  s_mac_pal_ctx.state = '\0';
  s_mac_pal_ctx.csma_nb = '\0';
  s_mac_pal_ctx.tx_retries = '\0';
  s_mac_pal_ctx._3_1_ = 0;
  s_mac_pal_ctx.tx_frame = (ezb_radio_frame_t *)0x0;
  s_mac_pal_ctx.op_timer.next = (timer_base *)0x0;
  s_mac_pal_ctx.op_timer.timer_func = (timer_func_t)0x0;
  s_mac_pal_ctx.op_timer.user_ctx = (void *)0x0;
  s_mac_pal_ctx.op_timer.fire_time.val = 0;
  s_mac_pal_ctx.radio_caps = 0;
  s_mac_pal_ctx._26_2_ = 0;
  s_mac_pal_ctx.tx_frame = (ezb_radio_frame_t *)ezb_plat_radio_get_transmit_buffer();
  if (s_mac_pal_ctx.tx_frame == (ezb_radio_frame_t *)0x0) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/mac/mac_pal.c",0x108,"mac_pal_init",
                  "s_mac_pal_ctx.tx_frame != ((void *)0)");
  }
  else {
    micro_timer_init(&s_mac_pal_ctx,timer_func_wrapper,0);
    iVar2 = ezb_plat_radio_is_enabled();
    if ((iVar2 == 0) || (eVar3 = mac_pal_disable(), eVar3 == 0)) {
      uVar1 = ezb_plat_radio_get_capabilities();
      s_mac_pal_ctx.radio_caps = uVar1;
      s_mac_pal_ctx._0_4_ = s_mac_pal_ctx._0_4_ & 0xffffff00;
      return;
    }
  }
  __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/mac/mac_pal.c",0x10d,"mac_pal_init",
                "(mac_pal_disable()) == 0");
  iVar2 = ezb_plat_radio_is_enabled();
  if ((iVar2 != 0) && (eVar3 = mac_pal_disable(), eVar3 != 0)) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/mac/mac_pal.c",0x116,"mac_pal_deinit",
                  "(mac_pal_disable()) == 0");
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  s_mac_pal_ctx.tx_frame = (ezb_radio_frame_t *)0x0;
  return;
}

