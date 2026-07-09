/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> mac_pal.o -> mac_pal_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void mac_pal_init(void)

{
  undefined2 uVar1;
  int iVar2;
  
  _s_mac_pal_ctx = 0;
  DAT_00010918 = 0;
  DAT_0001091c = 0;
  DAT_00010920 = 0;
  DAT_00010924 = 0;
  DAT_00010928 = 0;
  _DAT_0001092c = 0;
  DAT_00010918 = ezb_plat_radio_get_transmit_buffer();
  if (DAT_00010918 == 0) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/mac/mac_pal.c",0x108,"mac_pal_init",
                  "s_mac_pal_ctx.tx_frame != ((void *)0)");
  }
  else {
    micro_timer_init(&s_mac_pal_ctx,timer_func_wrapper,0);
    iVar2 = ezb_plat_radio_is_enabled();
    if ((iVar2 == 0) || (iVar2 = mac_pal_disable(), iVar2 == 0)) {
      uVar1 = ezb_plat_radio_get_capabilities();
      _DAT_0001092c = CONCAT22(DAT_0001092c_2,uVar1);
      _s_mac_pal_ctx = _s_mac_pal_ctx & 0xffffff00;
      return;
    }
  }
  __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/mac/mac_pal.c",0x10d,"mac_pal_init",
                "(mac_pal_disable()) == 0");
  iVar2 = ezb_plat_radio_is_enabled();
  if ((iVar2 != 0) && (iVar2 = mac_pal_disable(), iVar2 != 0)) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/mac/mac_pal.c",0x116,"mac_pal_deinit",
                  "(mac_pal_disable()) == 0");
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  DAT_00010918 = 0;
  return;
}

