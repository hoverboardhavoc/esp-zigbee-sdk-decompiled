/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_packet.o -> zdo_unsupported_req_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int zdo_unsupported_req_handler(int param_1)

{
  int iVar1;
  undefined1 uStack_29;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  uStack_28 = 0;
  uStack_24 = 0;
  uStack_20 = 0;
  uStack_1c = 0;
  uStack_18 = 0;
  uStack_14 = 0;
  if (param_1 == 0) {
    iVar1 = 0x80;
  }
  else if (*(ushort *)(param_1 + 2) < 0xfff8) {
    iVar1 = zdo_packet_response_init(&uStack_28,param_1,*(ushort *)(param_1 + 6) | 0x8000);
    if (iVar1 == 0) {
      uStack_29 = 0x84;
      zmsg_append_bytes(uStack_14,1,&uStack_29);
      iVar1 = ezb_err_to_zdp_status();
      if (iVar1 == 0) {
        iVar1 = zdo_packet_send(&uStack_28);
      }
      else {
        zdo_packet_free(&uStack_28);
      }
    }
  }
  else {
    iVar1 = 0xfe;
  }
  return iVar1;
}

