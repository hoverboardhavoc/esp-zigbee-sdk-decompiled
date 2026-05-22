/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-idf.remote.debug -> esp_zigbee_task_queue.o -> ezb_tasklet_signal_pending
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void ezb_tasklet_signal_pending(void)

{
  ssize_t sVar1;
  undefined4 uStack_18;
  uint64_t val;
  
  uStack_18 = 1;
  val._0_4_ = 0;
  sVar1 = write(s_task_queue_event_fd,&uStack_18,8);
  if (sVar1 == 8) {
    return;
  }
  __assert_func("//builds/thread_zigbee/esp-zigbee/src/platform_esp/esp-zigbee/platform/esp_zigbee_task_queue.c"
                ,0x25,"ezb_tasklet_signal_pending","ret == sizeof(val)");
  ezb_tasklet_signal_pending();
  return;
}

