/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_packet.o -> zdo_packet_req_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int zdo_packet_req_handler(int param_1)

{
  ushort uVar1;
  int iVar2;
  
  if (param_1 == 0) {
    return 0x80;
  }
  uVar1 = *(ushort *)(param_1 + 6);
  if (uVar1 < 0x20) {
    iVar2 = zdo_device_service_discovery_req_handler();
  }
  else if (uVar1 < 0x30) {
    iVar2 = zdo_bind_mgmt_req_handler();
  }
  else {
    if (0x3f < uVar1) goto _L0;
    iVar2 = zdo_nwk_mgmt_req_handler();
  }
  if (iVar2 != 0x84) {
    return iVar2;
  }
_L0:
  iVar2 = zdo_unsupported_req_handler(param_1);
  return iVar2;
}

