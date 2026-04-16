/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_bind_mgmt.o -> zdo_bind_mgmt_rsp_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

zdp_status_t zdo_bind_mgmt_rsp_handler(void *arg)

{
  zdp_status_t zVar1;
  
  if (arg == (void *)0x0) {
    zVar1 = 0x80;
  }
  else if (*(ushort *)((int)arg + 6) - 0x8021 < 2) {
    zVar1 = zdo_bind_and_unbind_rsp_handler((zdo_packet_t *)arg);
  }
  else {
    zVar1 = 0x84;
  }
  return zVar1;
}

