/*
 * Last changed at upstream commit d4fdccd9eea771602c7571d5f751435deed089e9
 * https://github.com/espressif/esp-zigbee-sdk/commit/d4fdccd9eea771602c7571d5f751435deed089e9
 * Upstream date: 2025-05-21 11:16:30 +0000
 * Upstream subject: esp-zigbee-sdk: (5d895722)
 * Source: libzboss_port.remote.debug -> zb_esp_osif.o -> zb_get_utc_time
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

__time_t zb_get_utc_time(void)

{
  int iVar1;
  undefined4 uVar2;
  timeval local_20 [3];
  
  if (get_utc_time_cb == (code *)0x0) {
    iVar1 = gettimeofday(local_20,(__timezone_ptr_t)0x0);
    if (iVar1 != 0) {
      zb_assert("/builds/thread_zigbee/esp-zboss/components/zboss_port/src/zb_esp_osif.c",0x115);
      uVar2 = esp_random();
      return uVar2;
    }
  }
  else {
    local_20[0].tv_sec = (*get_utc_time_cb)();
  }
  return local_20[0].tv_sec;
}

