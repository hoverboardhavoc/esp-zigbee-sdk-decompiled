/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-core.zczr.release -> zcl_packet.o -> zcl_packet_is_device_allowed.part.0
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

bool zcl_packet_is_device_allowed_part_0(int param_1)

{
  int iVar1;
  bool bVar2;
  
  if (*(short *)(param_1 + 0x16) != 3) {
    iVar1 = zcl_packet_is_general();
    bVar2 = false;
    if (iVar1 != 0) {
      bVar2 = true;
      if (5 < *(byte *)(param_1 + 0x20)) {
        bVar2 = *(byte *)(param_1 + 0x20) - 0xe < 3;
      }
    }
    return bVar2;
  }
  return true;
}

