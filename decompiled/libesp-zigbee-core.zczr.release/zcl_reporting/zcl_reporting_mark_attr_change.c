/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> zcl_reporting.o -> zcl_reporting_mark_attr_change
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 zcl_reporting_mark_attr_change(void)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  uint uStack_18;
  uint uStack_14;
  
  iVar2 = zcl_reporting_info_find();
  if (iVar2 == 0) {
    return 0;
  }
  iVar3 = zcl_get_attr_desc(*(undefined1 *)(iVar2 + 1),*(undefined2 *)(iVar2 + 4),
                            *(undefined1 *)(iVar2 + 8),*(undefined2 *)(iVar2 + 6),
                            *(undefined2 *)(iVar2 + 0x30));
  if (iVar3 == 0) {
    return 0;
  }
  uVar8 = *(uint *)(iVar2 + 8) >> 0xc;
  if ((uVar8 & 1) != 0) {
    *(byte *)(iVar2 + 9) = *(byte *)(iVar2 + 9) & 0xf | (byte)((uVar8 & 0xe) << 4);
    goto _L0;
  }
  iVar4 = zcl_attr_type_is_analog(*(undefined1 *)(iVar3 + 2));
  if (iVar4 == 0) {
    iVar4 = zcl_get_attr_value_size(*(undefined1 *)(iVar3 + 2),*(undefined4 *)(iVar3 + 8));
    if (iVar4 == 0xff) {
      return 0;
    }
    iVar9 = *(int *)(iVar2 + 0x20);
    iVar3 = crc32_next(0,*(undefined4 *)(iVar3 + 8),iVar4);
    if (iVar9 == iVar3) {
      return 0;
    }
    goto _L0;
  }
  zcl_read_attr_value(&uStack_18);
  bVar1 = *(byte *)(iVar3 + 2);
  if (bVar1 == 0x28) {
    iVar4 = (int)(char)uStack_18;
    iVar9 = (int)*(char *)(iVar2 + 0x20);
    iVar3 = iVar9 - iVar4;
    if (iVar9 < iVar4) {
      iVar3 = iVar4 - iVar9;
    }
    uVar8 = (uint)*(char *)(iVar2 + 0x18);
_L0:
    uVar8 = (uint)((int)uVar8 < iVar3);
  }
  else if (bVar1 < 0x29) {
    if (bVar1 == 0x23) {
_L0:
      uVar10 = *(uint *)(iVar2 + 0x20);
      uVar8 = uVar10 - uStack_18;
      if (uVar10 < uStack_18) {
        uVar8 = uStack_18 - uVar10;
      }
      uVar8 = (uint)(*(uint *)(iVar2 + 0x18) < uVar8);
    }
    else {
      if (bVar1 < 0x24) {
        if (bVar1 == 0x21) {
          uStack_18 = uStack_18 & 0xffff;
          uVar8 = (uint)*(ushort *)(iVar2 + 0x20);
          iVar3 = uVar8 - uStack_18;
          if (uVar8 < uStack_18) {
            iVar3 = uStack_18 - uVar8;
          }
          uVar8 = (uint)*(ushort *)(iVar2 + 0x18);
        }
        else {
          if (bVar1 == 0x22) goto _L0;
          if (bVar1 != 0x20) {
            return 0;
          }
          uStack_18 = uStack_18 & 0xff;
          uVar8 = (uint)*(byte *)(iVar2 + 0x20);
          iVar3 = uVar8 - uStack_18;
          if (uVar8 < uStack_18) {
            iVar3 = uStack_18 - uVar8;
          }
          uVar8 = (uint)*(byte *)(iVar2 + 0x18);
        }
        goto _L0;
      }
      if ((bVar1 != 0x25) && (bVar1 != 0x27)) {
        return 0;
      }
      uVar10 = *(uint *)(iVar2 + 0x24);
      uVar8 = *(uint *)(iVar2 + 0x20);
      if ((uVar10 < uStack_14) || ((uStack_14 == uVar10 && (uVar8 < uStack_18)))) {
        uVar7 = uStack_18 - uVar8;
        uVar10 = (uStack_14 - uVar10) - (uint)(uStack_18 < uVar7);
      }
      else {
        uVar7 = uVar8 - uStack_18;
        uVar10 = (uVar10 - uStack_14) - (uint)(uVar8 < uVar7);
      }
      uVar6 = *(uint *)(iVar2 + 0x1c);
      uVar8 = 1;
      if (uVar10 <= uVar6) goto _L0;
    }
  }
  else {
    if (bVar1 != 0x2d) {
      if (bVar1 < 0x2e) {
        if ((bVar1 == 0x2a) || (bVar1 == 0x2b)) {
          iVar4 = *(int *)(iVar2 + 0x20);
          iVar3 = iVar4 - uStack_18;
          if (iVar4 < (int)uStack_18) {
            iVar3 = uStack_18 - iVar4;
          }
          uVar8 = *(uint *)(iVar2 + 0x18);
        }
        else {
          if (bVar1 != 0x29) {
            return 0;
          }
          iVar4 = (int)(short)uStack_18;
          iVar9 = (int)*(short *)(iVar2 + 0x20);
          iVar3 = iVar9 - iVar4;
          if (iVar9 < iVar4) {
            iVar3 = iVar4 - iVar9;
          }
          uVar8 = (uint)*(short *)(iVar2 + 0x18);
        }
        goto _L0;
      }
      if (bVar1 != 0x2f) {
        if (bVar1 != 0x39) {
          return 0;
        }
        uVar10 = *(uint *)(iVar2 + 0x20);
        iVar3 = __gtsf2(uStack_18,uVar10);
        uVar8 = uVar10;
        if (0 < iVar3) {
          uVar8 = uStack_18;
          uStack_18 = uVar10;
        }
        uVar5 = __subsf3(uVar8,uStack_18);
        uVar8 = __ltsf2(*(undefined4 *)(iVar2 + 0x18),uVar5);
        uVar8 = uVar8 >> 0x1f;
        goto _L0;
      }
    }
    uVar10 = *(uint *)(iVar2 + 0x24);
    uVar8 = *(uint *)(iVar2 + 0x20);
    if (((int)uVar10 < (int)uStack_14) || ((uStack_14 == uVar10 && (uVar8 < uStack_18)))) {
      uVar7 = uStack_18 - uVar8;
      uVar10 = (uStack_14 - uVar10) - (uint)(uStack_18 < uVar7);
    }
    else {
      uVar7 = uVar8 - uStack_18;
      uVar10 = (uVar10 - uStack_14) - (uint)(uVar8 < uVar7);
    }
    uVar6 = *(uint *)(iVar2 + 0x1c);
    uVar8 = 1;
    if ((int)uVar10 <= (int)uVar6) {
_L0:
      uVar8 = 1;
      if ((uVar6 != uVar10) || (uVar7 <= *(uint *)(iVar2 + 0x18))) {
        uVar8 = 0;
      }
    }
  }
_L0:
  if (uVar8 == 0) {
    return 0;
  }
_L0:
  bVar1 = *(byte *)(iVar2 + 9);
  *(byte *)(iVar2 + 9) = bVar1 | 0x20;
  if ((9U >> (bVar1 & 0xf) & 1) != 0) {
    *(byte *)(iVar2 + 9) = bVar1 & 0xf0 | 0x23;
    process_attr_report(iVar2);
  }
  return 0;
}

