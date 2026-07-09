/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> zcl_reporting.o -> check_attr_delta
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

bool check_attr_delta(int param_1)

{
  byte bVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  bool bVar9;
  uint uStack_18;
  uint uStack_14;
  
  if (param_1 == 0) {
    bVar9 = false;
  }
  else {
    iVar4 = zcl_get_attr_desc(*(undefined1 *)(param_1 + 1),*(undefined2 *)(param_1 + 4),
                              *(undefined1 *)(param_1 + 8),*(undefined2 *)(param_1 + 6),
                              *(undefined2 *)(param_1 + 0x30));
    if (iVar4 == 0) {
      bVar9 = false;
    }
    else {
      uVar7 = *(uint *)(param_1 + 8) >> 0xc;
      if ((uVar7 & 1) == 0) {
        iVar5 = zcl_attr_type_is_analog(*(undefined1 *)(iVar4 + 2));
        if (iVar5 == 0) {
          iVar5 = zcl_get_attr_value_size(*(undefined1 *)(iVar4 + 2),*(undefined4 *)(iVar4 + 8));
          bVar9 = false;
          if ((iVar5 != 0xff) &&
             (iVar2 = *(int *)(param_1 + 0x20),
             iVar4 = crc32_next(0,*(undefined4 *)(iVar4 + 8),iVar5), iVar2 != iVar4)) {
            bVar9 = true;
          }
        }
        else {
          zcl_read_attr_value(&uStack_18,*(undefined4 *)(iVar4 + 8),*(undefined1 *)(iVar4 + 2));
          bVar1 = *(byte *)(iVar4 + 2);
          if (bVar1 == 0x28) {
            iVar4 = (int)(char)uStack_18;
            iVar5 = (int)*(char *)(param_1 + 0x20);
            if (iVar5 < iVar4) {
              iVar4 = iVar4 - iVar5;
            }
            else {
              iVar4 = iVar5 - iVar4;
            }
            bVar9 = *(char *)(param_1 + 0x18) < iVar4;
          }
          else if (bVar1 < 0x29) {
            if (bVar1 == 0x23) {
              uVar7 = *(uint *)(param_1 + 0x20);
              if (uVar7 < uStack_18) {
                uStack_18 = uStack_18 - uVar7;
              }
              else {
                uStack_18 = uVar7 - uStack_18;
              }
              bVar9 = *(uint *)(param_1 + 0x18) < uStack_18;
            }
            else if (bVar1 < 0x24) {
              if (bVar1 == 0x21) {
                uStack_18 = uStack_18 & 0xffff;
                uVar7 = (uint)*(ushort *)(param_1 + 0x20);
                if (uVar7 < uStack_18) {
                  iVar4 = uStack_18 - uVar7;
                }
                else {
                  iVar4 = uVar7 - uStack_18;
                }
                bVar9 = (int)(uint)*(ushort *)(param_1 + 0x18) < iVar4;
              }
              else if (bVar1 == 0x22) {
                uVar7 = *(uint *)(param_1 + 0x20);
                if (uVar7 < uStack_18) {
                  uStack_18 = uStack_18 - uVar7;
                }
                else {
                  uStack_18 = uVar7 - uStack_18;
                }
                bVar9 = *(uint *)(param_1 + 0x18) < uStack_18;
              }
              else if (bVar1 == 0x20) {
                uStack_18 = uStack_18 & 0xff;
                uVar7 = (uint)*(byte *)(param_1 + 0x20);
                if (uVar7 < uStack_18) {
                  iVar4 = uStack_18 - uVar7;
                }
                else {
                  iVar4 = uVar7 - uStack_18;
                }
                bVar9 = (int)(uint)*(byte *)(param_1 + 0x18) < iVar4;
              }
              else {
                bVar9 = false;
              }
            }
            else if (bVar1 == 0x25) {
              uVar7 = *(uint *)(param_1 + 0x20);
              uVar8 = *(uint *)(param_1 + 0x24);
              if ((uVar8 < uStack_14) || ((uStack_14 == uVar8 && (uVar7 < uStack_18)))) {
                uVar6 = uStack_18 - uVar7;
                uVar7 = (uStack_14 - uVar8) - (uint)(uStack_18 < uVar6);
              }
              else {
                uVar6 = uVar7 - uStack_18;
                uVar7 = (uVar8 - uStack_14) - (uint)(uVar7 < uVar6);
              }
              bVar9 = true;
              if ((uVar7 <= *(uint *)(param_1 + 0x1c)) &&
                 ((uVar7 != *(uint *)(param_1 + 0x1c) || (uVar6 <= *(uint *)(param_1 + 0x18))))) {
                bVar9 = false;
              }
            }
            else if (bVar1 == 0x27) {
              uVar7 = *(uint *)(param_1 + 0x20);
              uVar8 = *(uint *)(param_1 + 0x24);
              if ((uVar8 < uStack_14) || ((uStack_14 == uVar8 && (uVar7 < uStack_18)))) {
                uVar6 = uStack_18 - uVar7;
                uVar7 = (uStack_14 - uVar8) - (uint)(uStack_18 < uVar6);
              }
              else {
                uVar6 = uVar7 - uStack_18;
                uVar7 = (uVar8 - uStack_14) - (uint)(uVar7 < uVar6);
              }
              bVar9 = true;
              if ((uVar7 <= *(uint *)(param_1 + 0x1c)) &&
                 ((uVar7 != *(uint *)(param_1 + 0x1c) || (uVar6 <= *(uint *)(param_1 + 0x18))))) {
                bVar9 = false;
              }
            }
            else {
              bVar9 = false;
            }
          }
          else if (bVar1 == 0x2d) {
            uVar7 = *(uint *)(param_1 + 0x20);
            uVar8 = *(uint *)(param_1 + 0x24);
            if (((int)uVar8 < (int)uStack_14) || ((uStack_14 == uVar8 && (uVar7 < uStack_18)))) {
              uVar6 = uStack_18 - uVar7;
              iVar4 = (uStack_14 - uVar8) - (uint)(uStack_18 < uVar6);
            }
            else {
              uVar6 = uVar7 - uStack_18;
              iVar4 = (uVar8 - uStack_14) - (uint)(uVar7 < uVar6);
            }
            bVar9 = true;
            if ((iVar4 <= *(int *)(param_1 + 0x1c)) &&
               ((iVar4 != *(int *)(param_1 + 0x1c) || (uVar6 <= *(uint *)(param_1 + 0x18))))) {
              bVar9 = false;
            }
          }
          else if (bVar1 < 0x2e) {
            if (bVar1 == 0x2a) {
              iVar4 = *(int *)(param_1 + 0x20);
              if (iVar4 < (int)uStack_18) {
                iVar4 = uStack_18 - iVar4;
              }
              else {
                iVar4 = iVar4 - uStack_18;
              }
              bVar9 = *(int *)(param_1 + 0x18) < iVar4;
            }
            else if (bVar1 == 0x2b) {
              iVar4 = *(int *)(param_1 + 0x20);
              if (iVar4 < (int)uStack_18) {
                iVar4 = uStack_18 - iVar4;
              }
              else {
                iVar4 = iVar4 - uStack_18;
              }
              bVar9 = *(int *)(param_1 + 0x18) < iVar4;
            }
            else if (bVar1 == 0x29) {
              iVar4 = (int)(short)uStack_18;
              iVar5 = (int)*(short *)(param_1 + 0x20);
              if (iVar5 < iVar4) {
                iVar4 = iVar4 - iVar5;
              }
              else {
                iVar4 = iVar5 - iVar4;
              }
              bVar9 = *(short *)(param_1 + 0x18) < iVar4;
            }
            else {
              bVar9 = false;
            }
          }
          else if (bVar1 == 0x2f) {
            uVar7 = *(uint *)(param_1 + 0x20);
            uVar8 = *(uint *)(param_1 + 0x24);
            if (((int)uVar8 < (int)uStack_14) || ((uStack_14 == uVar8 && (uVar7 < uStack_18)))) {
              uVar6 = uStack_18 - uVar7;
              iVar4 = (uStack_14 - uVar8) - (uint)(uStack_18 < uVar6);
            }
            else {
              uVar6 = uVar7 - uStack_18;
              iVar4 = (uVar8 - uStack_14) - (uint)(uVar7 < uVar6);
            }
            bVar9 = true;
            if ((iVar4 <= *(int *)(param_1 + 0x1c)) &&
               ((iVar4 != *(int *)(param_1 + 0x1c) || (uVar6 <= *(uint *)(param_1 + 0x18))))) {
              bVar9 = false;
            }
          }
          else if (bVar1 == 0x39) {
            uVar3 = *(undefined4 *)(param_1 + 0x20);
            iVar4 = __gtsf2(uStack_18,uVar3);
            if (iVar4 < 1) {
              uVar3 = __subsf3(uVar3,uStack_18);
            }
            else {
              uVar3 = __subsf3(uStack_18,uVar3);
            }
            iVar4 = __ltsf2(*(undefined4 *)(param_1 + 0x18),uVar3);
            bVar9 = iVar4 < 0;
          }
          else {
            bVar9 = false;
          }
        }
      }
      else {
        *(byte *)(param_1 + 9) = *(byte *)(param_1 + 9) & 0xf | (byte)((uVar7 & 0xe) << 4);
        bVar9 = true;
      }
    }
  }
  return bVar9;
}

