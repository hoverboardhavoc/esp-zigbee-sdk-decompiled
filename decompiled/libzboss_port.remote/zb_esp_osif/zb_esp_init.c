/*
 * Last changed at upstream commit e883f431f54d7744605c05ac3bc92898d04315c0
 * https://github.com/espressif/esp-zigbee-sdk/commit/e883f431f54d7744605c05ac3bc92898d04315c0
 * Upstream date: 2025-02-14 17:01:07 +0800
 * Upstream subject: esp-zigbee-sdk: (f9a23626)
 * Source: libzboss_port.remote -> zb_esp_osif.o -> zb_esp_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zb_esp_init(void)

{
  int iVar1;
  undefined4 auStack_14 [4];
  
  auStack_14[0] = 3;
  esp_vfs_eventfd_register(auStack_14);
  iVar1 = zb_esp_osif_lock_init();
  if (iVar1 != 0) {
                    /* WARNING: Subroutine does not return */
    abort();
  }
  s_zb_sched_fd = eventfd(0,0x10);
  if (s_zb_sched_fd < 1) {
    zb_assert("/builds/thread_zigbee/esp-zboss/components/zboss_port/src/zb_esp_osif.c",0x9d);
  }
  return;
}

