/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> mac_pal.o -> mac_pal_deinit
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void mac_pal_deinit(void)

{
  int iVar1;
  ezb_err_t eVar2;
  
  iVar1 = ezb_plat_radio_is_enabled();
  if ((iVar1 != 0) && (eVar2 = mac_pal_disable(), eVar2 != 0)) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/mac/mac_pal.c",0x116,"mac_pal_deinit",
                  "(mac_pal_disable()) == 0");
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  s_mac_pal_ctx.tx_frame = (ezb_radio_frame_t *)0x0;
  return;
}

