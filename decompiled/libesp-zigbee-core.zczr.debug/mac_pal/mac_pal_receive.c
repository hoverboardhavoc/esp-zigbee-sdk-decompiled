/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> mac_pal.o -> mac_pal_receive
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t mac_pal_receive(uint8_t page,uint8_t channel)

{
  int unaff_s0;
  undefined3 in_register_00002029;
  int iVar1;
  undefined3 in_register_0000202d;
  
  if (CONCAT31(in_register_00002029,page) == 0) {
    unaff_s0 = ezb_plat_radio_receive(CONCAT31(in_register_0000202d,channel));
    iVar1 = unaff_s0;
    if (unaff_s0 == 0) {
      set_state(MAC_PAL_STATE_RECEIVE);
      return 0;
    }
  }
  else {
    iVar1 = __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/mac/mac_pal.c",0x164,
                          "mac_pal_receive","page == 0");
  }
  log_write(2,"mac_pal.c","RadioReceive() failed, error: %d",iVar1);
  return unaff_s0;
}

