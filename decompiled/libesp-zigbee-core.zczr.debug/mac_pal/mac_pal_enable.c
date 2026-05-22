/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> mac_pal.o -> mac_pal_enable
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t mac_pal_enable(void)

{
  int iVar1;
  
  if (s_mac_pal_ctx.state == '\0') {
    iVar1 = ezb_plat_radio_enable();
    if ((iVar1 != 0) || (iVar1 = ezb_plat_radio_sleep(), iVar1 != 0)) {
      __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/mac/mac_pal.c",0x144,
                    "mac_pal_enable","error == 0");
      micro_timer_stop(&s_mac_pal_ctx);
      iVar1 = ezb_plat_radio_sleep();
      if ((iVar1 == 0) && (iVar1 = ezb_plat_radio_disable(), iVar1 == 0)) {
        set_state(MAC_PAL_STATE_DISABLED);
      }
      return iVar1;
    }
    set_state(MAC_PAL_STATE_SLEEP);
  }
  return 0;
}

