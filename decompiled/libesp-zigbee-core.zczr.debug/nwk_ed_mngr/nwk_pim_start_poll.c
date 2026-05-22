/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_ed_mngr.o -> nwk_pim_start_poll
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void nwk_pim_start_poll(void)

{
  int iVar1;
  
  iVar1 = nwk_is_device_zed();
  if (iVar1 == 0) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/nwk/nwk_ed_mngr.c",0x15a,
                  "nwk_pim_start_poll","nwk_is_device_zed()");
  }
  else {
    iVar1 = core_globals_get();
    if ((*(byte *)(iVar1 + 0xb16) & 0x20) != 0) {
      return;
    }
  }
  iVar1 = core_globals_get();
  *(byte *)(iVar1 + 0xb16) = *(byte *)(iVar1 + 0xb16) | 0x20;
  nwk_pim_schedule_next_poll(true);
  return;
}

