/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> mac.o -> mac_iface_set_pib_attr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

uint mac_iface_set_pib_attr(int *param_1,uint param_2,uint *param_3)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  byte bVar6;
  int iVar7;
  undefined1 uVar8;
  uint uVar9;
  
  iVar7 = *param_1;
  if (param_3 == (uint *)0x0) {
    uVar9 = 2;
  }
  else if (param_2 == 0x50) {
    mac_set_panid(iVar7,(short)*param_3);
    uVar9 = 0;
  }
  else {
    if (param_2 < 0x51) {
      if (param_2 == 0x49) {
        *(byte *)(iVar7 + 0xd) = (byte)*param_3;
        return 0;
      }
      if (param_2 < 0x4a) {
        if (param_2 == 0x45) {
          *(uint *)(iVar7 + 0x24) = *param_3;
          return 0;
        }
        if (param_2 < 0x46) {
          if (param_2 == 0x40) {
            mac_set_extended_address(iVar7,param_3);
            return 0;
          }
          if (param_2 == 0x41) {
            *(byte *)(iVar7 + 0x2a) = *(byte *)(iVar7 + 0x2a) & 0xfe | (byte)*param_3 & 1;
            return 0;
          }
          uVar9 = 0xf4;
        }
        else {
          if (param_2 == 0x46) {
            *(byte *)(iVar7 + 0x23) = (byte)*param_3;
            return 0;
          }
          if (param_2 == 0x47) {
            uVar9 = 0xfb;
          }
          else {
            uVar9 = 0xf4;
          }
        }
      }
      else {
        if (param_2 == 0x4c) {
          *(byte *)(iVar7 + 0xc) = (byte)*param_3;
          return 0;
        }
        if (param_2 < 0x4d) {
          if (param_2 == 0x4a) {
            bVar1 = *(byte *)((int)param_3 + 1);
            bVar2 = *(byte *)((int)param_3 + 2);
            bVar3 = *(byte *)((int)param_3 + 3);
            uVar9 = param_3[1];
            bVar4 = *(byte *)((int)param_3 + 5);
            bVar5 = *(byte *)((int)param_3 + 6);
            bVar6 = *(byte *)((int)param_3 + 7);
            *(byte *)(iVar7 + 0x10) = (byte)*param_3;
            *(byte *)(iVar7 + 0x11) = bVar1;
            *(byte *)(iVar7 + 0x12) = bVar2;
            *(byte *)(iVar7 + 0x13) = bVar3;
            *(byte *)(iVar7 + 0x14) = (byte)uVar9;
            *(byte *)(iVar7 + 0x15) = bVar4;
            *(byte *)(iVar7 + 0x16) = bVar5;
            *(byte *)(iVar7 + 0x17) = bVar6;
            return 0;
          }
          if (param_2 == 0x4b) {
            *(short *)(iVar7 + 0xe) = (short)*param_3;
            return 0;
          }
          uVar9 = 0xf4;
        }
        else {
          if (param_2 == 0x4e) {
            *(byte *)(iVar7 + 0x22) = (byte)*param_3;
            return 0;
          }
          if (param_2 == 0x4f) {
            *(byte *)(iVar7 + 0x20) = (byte)*param_3;
            return 0;
          }
          uVar9 = 0xf4;
        }
      }
    }
    else {
      if (param_2 == 0x58) {
        *(short *)(iVar7 + 0x1c) = (short)*param_3;
        return 0;
      }
      if (param_2 < 0x59) {
        if (param_2 == 0x54) {
          uVar9 = 0xfb;
        }
        else if (param_2 < 0x55) {
          if (param_2 == 0x52) {
            mac_set_rx_on_when_idle(iVar7,(byte)*param_3);
            return 0;
          }
          if (param_2 == 0x53) {
            mac_set_short_address(iVar7,(short)*param_3);
            return 0;
          }
          uVar9 = 0xf4;
        }
        else {
          if (param_2 == 0x55) {
            *(short *)(iVar7 + 0x28) = (short)*param_3;
            return 0;
          }
          if (param_2 == 0x57) {
            *(byte *)(iVar7 + 0x21) = (byte)*param_3;
            return 0;
          }
          uVar9 = 0xf4;
        }
      }
      else if (param_2 == 0x60) {
        uVar9 = 0xfb;
      }
      else if (param_2 < 0x61) {
        if (param_2 == 0x5a) {
          *(byte *)(iVar7 + 0x1f) = (byte)*param_3;
          return 0;
        }
        if (param_2 == 0x5d) {
          uVar9 = 0xfb;
        }
        else {
          if (param_2 == 0x59) {
            *(byte *)(iVar7 + 0x1e) = (byte)*param_3;
            return 0;
          }
          uVar9 = 0xf4;
        }
      }
      else {
        if (param_2 == 0x62) {
          if ((*param_3 & 0x7ffffff) != 0) {
            uVar9 = *param_3;
            uVar8 = __ctzsi2(uVar9 & 0x7ffffff);
            mac_set_temporary_channel(iVar7,uVar9 >> 0x1b,uVar8);
            return 0;
          }
          mac_clear_temporary_channel(iVar7);
          return 0;
        }
        if (param_2 == 99) {
          uVar9 = 0xfb;
        }
        else {
          if (param_2 == 0x61) {
            if ((*param_3 & 0x7ffffff) != 0) {
              uVar9 = *param_3;
              uVar8 = __ctzsi2(uVar9 & 0x7ffffff);
              mac_set_pan_channel(iVar7,uVar9 >> 0x1b,uVar8);
              return 0;
            }
            return 2;
          }
          uVar9 = 0xf4;
        }
      }
    }
    uVar9 = uVar9 | 0x100;
  }
  return uVar9;
}

