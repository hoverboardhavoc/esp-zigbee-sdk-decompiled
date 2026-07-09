/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> zdo_packet.o -> zdo_packet_req_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 zdo_packet_req_handler(int param_1)

{
  ushort uVar1;
  undefined4 uVar2;
  
  if (param_1 == 0) {
    uVar2 = 0x80;
  }
  else {
    uVar1 = *(ushort *)(param_1 + 6);
    if (uVar1 < 0x20) {
      uVar2 = zdo_device_service_discovery_req_handler();
      return uVar2;
    }
    if (uVar1 < 0x30) {
      uVar2 = zdo_bind_mgmt_req_handler();
      return uVar2;
    }
    uVar2 = 0x84;
    if (uVar1 < 0x40) {
      uVar2 = zdo_nwk_mgmt_req_handler();
      return uVar2;
    }
  }
  return uVar2;
}

