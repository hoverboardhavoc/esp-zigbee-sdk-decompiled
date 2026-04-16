/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee.debug -> esp_zigbee.o -> esp_zigbee_launch_mainloop
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Type propagation algorithm not settling */
/* WARNING: Unknown calling convention */

esp_err_t esp_zigbee_launch_mainloop(void)

{
  int iVar1;
  undefined4 uStack_44;
  undefined1 auStack_40 [4];
  esp_zigbee_mainloop_context_t mainloop;
  
  while( true ) {
    for (iVar1 = 2; iVar1 != 0; iVar1 = iVar1 + -1) {
      *(undefined4 *)((int)(&mainloop.read_fds + -1) + iVar1 * 4) = 0;
    }
    for (iVar1 = 2; iVar1 != 0; iVar1 = iVar1 + -1) {
      mainloop.read_fds.__fds_bits[iVar1] = 0;
    }
    for (iVar1 = 2; iVar1 != 0; iVar1 = iVar1 + -1) {
      mainloop.write_fds.__fds_bits[iVar1] = 0;
    }
    mainloop.error_fds.__fds_bits[1] = 0xffffffff;
    mainloop._28_4_ = 10;
    mainloop.timeout.tv_sec._0_4_ = 0;
    mainloop.timeout.tv_sec._4_4_ = 0;
    esp_zigbee_lock_acquire(0xffffffff);
    esp_zigbee_platform_update(auStack_40);
    esp_zigbee_sleep_process();
    esp_zigbee_lock_release();
    iVar1 = select(mainloop.error_fds.__fds_bits[1] + 1,(fd_set *)auStack_40,
                   (fd_set *)(mainloop.read_fds.__fds_bits + 1),
                   (fd_set *)(mainloop.write_fds.__fds_bits + 1),(timeval *)&mainloop.field_0x1c);
    if (iVar1 < 0) break;
    esp_zigbee_lock_acquire(0xffffffff);
    iVar1 = esp_zigbee_platform_process(auStack_40);
    esp_zigbee_lock_release();
    if (iVar1 != 0) {
      esp_log(0x11,"ESP-ZIGBEE","esp_zigbee_platform_process failed");
      return iVar1;
    }
  }
  esp_log(0x11,"ESP-ZIGBEE","Zigbee system polling failed");
  return -1;
}

