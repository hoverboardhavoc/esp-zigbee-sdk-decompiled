/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee.release -> zcl_core_compat.o -> time_cluster_get_utc_time
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

uint32_t time_cluster_get_utc_time(void)

{
  uint32_t uVar1;
  undefined1 local_20 [4];
  timeval utc_time;
  
  if (s_get_utc_time_cb != (get_utc_time_callback_t)0x0) {
                    /* WARNING: Could not recover jumptable at 0x0001049e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (*s_get_utc_time_cb)();
    return uVar1;
  }
  local_20 = (undefined1  [4])0x0;
  utc_time.tv_sec._0_4_ = 0;
  utc_time.tv_sec._4_4_ = 0;
  utc_time.tv_usec = 0;
  gettimeofday((timeval *)local_20,(__timezone_ptr_t)0x0);
  return (uint32_t)local_20;
}

