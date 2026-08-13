/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-core.zczr.debug -> zcl_packet.o -> zcl_packet_is_device_allowed
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int zcl_packet_is_device_allowed(int param_1,int param_2)

{
  undefined1 uVar1;
  byte bVar2;
  int iVar3;
  
  if (param_2 == 0) {
    uVar1 = *(undefined1 *)(param_1 + 0x14);
  }
  else {
    uVar1 = *(undefined1 *)(param_1 + 0x15);
  }
  iVar3 = zcl_basic_device_is_enabled(uVar1);
  if (iVar3 == 0) {
    if (*(short *)(param_1 + 0x16) == 3) {
      iVar3 = 1;
    }
    else {
      iVar3 = zcl_packet_is_general(param_1);
      if (iVar3 == 0) {
        iVar3 = 0;
      }
      else {
        bVar2 = *(byte *)(param_1 + 0x20);
        if (bVar2 == 5) {
          iVar3 = 1;
        }
        else if (bVar2 < 6) {
          if (bVar2 == 3) {
            iVar3 = 1;
          }
          else if (bVar2 < 4) {
            if (bVar2 < 2) {
              iVar3 = 1;
            }
            else if (bVar2 == 2) {
              iVar3 = 1;
            }
            else {
              iVar3 = 0;
            }
          }
          else if (bVar2 == 4) {
            iVar3 = 1;
          }
          else {
            iVar3 = 0;
          }
        }
        else if (bVar2 == 0xf) {
          iVar3 = 1;
        }
        else if (bVar2 == 0x10) {
          iVar3 = 1;
        }
        else if (bVar2 == 0xe) {
          iVar3 = 1;
        }
        else {
          iVar3 = 0;
        }
      }
    }
  }
  return iVar3;
}

