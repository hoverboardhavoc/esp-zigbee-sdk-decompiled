/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-core.zczr.release -> zdo_packet.o -> zdo_packet_req_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int zdo_packet_req_handler(int param_1)

{
  ushort uVar1;
  int iVar2;
  undefined1 uStack_29;
  undefined1 auStack_28 [20];
  undefined4 uStack_14;
  
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
  memset(auStack_28,0,0x18);
  iVar2 = 0xfe;
  if ((*(ushort *)(param_1 + 2) < 0xfff8) &&
     (iVar2 = zdo_packet_response_init(auStack_28,param_1,*(ushort *)(param_1 + 6) | 0x8000),
     iVar2 == 0)) {
    uStack_29 = 0x84;
    zmsg_append_bytes(uStack_14,1,&uStack_29);
    iVar2 = ezb_err_to_zdp_status();
    if (iVar2 == 0) {
      iVar2 = zdo_packet_send();
    }
    else {
      zdo_packet_free(auStack_28);
    }
  }
  return iVar2;
}

