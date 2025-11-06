/*
 * Last changed at upstream commit ef60059b4d605d61a0103f81567229692f238007
 * https://github.com/espressif/esp-zigbee-sdk/commit/ef60059b4d605d61a0103f81567229692f238007
 * Upstream date: 2025-11-06 11:58:56 +0800
 * Upstream subject: esp-zigbee-sdk: (79cb709a)
 * Source: libzboss_port.remote -> zb_esp_osif.o -> zb_get_utc_time
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

__time_t zb_get_utc_time(void)

{
  undefined4 uVar1;
  int iVar2;
  timeval local_20 [3];
  
  if (get_utc_time_cb != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x000104f8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (*get_utc_time_cb)();
    return uVar1;
  }
  iVar2 = gettimeofday(local_20,(__timezone_ptr_t)0x0);
  if (iVar2 != 0) {
    zb_assert("/builds/thread_zigbee/esp-zboss/components/zboss_port/src/zb_esp_osif.c",0x115);
  }
  return local_20[0].tv_sec;
}

