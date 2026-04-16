/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> zcl_reporting.o -> zcl_reporting_mark_attr_change
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Variable defined which should be unmapped: attr_value */
/* WARNING: Unknown calling convention */

ezb_err_t zcl_reporting_mark_attr_change
                    (uint8_t ep_id,uint16_t cluster_id,uint8_t role,uint16_t attr_id,
                    uint16_t manuf_code)

{
  byte bVar1;
  zcl_reporting_info_t *info;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  uint32_t uVar10;
  uint uStack_18;
  zcl_attr_variable_t attr_value;
  
  info = zcl_reporting_info_find(ep_id,cluster_id,role,attr_id,manuf_code);
  if (info == (zcl_reporting_info_t *)0x0) {
    return 0;
  }
  iVar2 = zcl_get_attr_desc(info->ep_id,info->cluster_id,info->cluster_role,info->attr_id,
                            info->manuf_code);
  if (iVar2 == 0) {
    return 0;
  }
  uVar6 = *(uint *)&info->cluster_role >> 0xc;
  if ((uVar6 & 1) != 0) {
    info->field_0x9 = info->field_0x9 & 0xf | (byte)((uVar6 & 0xe) << 4);
    goto _L0;
  }
  iVar3 = zcl_attr_type_is_analog(*(undefined1 *)(iVar2 + 2));
  if (iVar3 == 0) {
    iVar3 = zcl_get_attr_value_size(*(undefined1 *)(iVar2 + 2),*(undefined4 *)(iVar2 + 8));
    if (iVar3 == 0xff) {
      return 0;
    }
    iVar8 = *(int *)((int)&info->u + 0x10);
    iVar2 = crc32_next(0,*(undefined4 *)(iVar2 + 8),iVar3);
    if (iVar8 == iVar2) {
      return 0;
    }
    goto _L0;
  }
  zcl_read_attr_value(&uStack_18);
  bVar1 = *(byte *)(iVar2 + 2);
  if (bVar1 == 0x28) {
    iVar3 = (int)(char)uStack_18;
    iVar8 = (int)*(char *)((int)&info->u + 0x10);
    iVar2 = iVar8 - iVar3;
    if (iVar8 < iVar3) {
      iVar2 = iVar3 - iVar8;
    }
    uVar6 = (uint)*(char *)((int)&info->u + 8);
_L0:
    uVar6 = (uint)((int)uVar6 < iVar2);
  }
  else if (bVar1 < 0x29) {
    if (bVar1 == 0x23) {
_L0:
      uVar9 = *(uint *)((int)&info->u + 0x10);
      uVar6 = uVar9 - uStack_18;
      if (uVar9 < uStack_18) {
        uVar6 = uStack_18 - uVar9;
      }
      uVar6 = (uint)(*(uint *)((int)&info->u + 8) < uVar6);
    }
    else {
      if (bVar1 < 0x24) {
        if (bVar1 == 0x21) {
          uStack_18 = uStack_18 & 0xffff;
          uVar6 = (uint)*(ushort *)((int)&info->u + 0x10);
          iVar2 = uVar6 - uStack_18;
          if (uVar6 < uStack_18) {
            iVar2 = uStack_18 - uVar6;
          }
          uVar6 = (uint)*(ushort *)((int)&info->u + 8);
        }
        else {
          if (bVar1 == 0x22) goto _L0;
          if (bVar1 != 0x20) {
            return 0;
          }
          uStack_18 = uStack_18 & 0xff;
          uVar6 = (uint)*(byte *)((int)&info->u + 0x10);
          iVar2 = uVar6 - uStack_18;
          if (uVar6 < uStack_18) {
            iVar2 = uStack_18 - uVar6;
          }
          uVar6 = (uint)*(byte *)((int)&info->u + 8);
        }
        goto _L0;
      }
      if ((bVar1 != 0x25) && (bVar1 != 0x27)) {
        return 0;
      }
      uVar7 = *(uint *)((int)&info->u + 0x14);
      uVar6 = *(uint *)((int)&info->u + 0x10);
      if ((uVar7 < attr_value.u24) || ((attr_value.u24 == uVar7 && (uVar6 < uStack_18)))) {
        uVar9 = uStack_18 - uVar6;
        uVar7 = (attr_value.u24 - uVar7) - (uint)(uStack_18 < uVar9);
      }
      else {
        uVar9 = uVar6 - uStack_18;
        uVar7 = (uVar7 - attr_value._0_4_) - (uint)(uVar6 < uVar9);
      }
      uVar5 = *(uint *)((int)&info->u + 0xc);
      uVar6 = 1;
      if (uVar7 <= uVar5) goto _L0;
    }
  }
  else {
    if (bVar1 != 0x2d) {
      if (bVar1 < 0x2e) {
        if ((bVar1 == 0x2a) || (bVar1 == 0x2b)) {
          iVar3 = *(int *)((int)&info->u + 0x10);
          iVar2 = iVar3 - uStack_18;
          if (iVar3 < (int)uStack_18) {
            iVar2 = uStack_18 - iVar3;
          }
          uVar6 = *(uint *)((int)&info->u + 8);
        }
        else {
          if (bVar1 != 0x29) {
            return 0;
          }
          iVar3 = (int)(short)uStack_18;
          iVar8 = (int)*(short *)((int)&info->u + 0x10);
          iVar2 = iVar8 - iVar3;
          if (iVar8 < iVar3) {
            iVar2 = iVar3 - iVar8;
          }
          uVar6 = (uint)*(short *)((int)&info->u + 8);
        }
        goto _L0;
      }
      if (bVar1 != 0x2f) {
        if (bVar1 != 0x39) {
          return 0;
        }
        uVar9 = *(uint *)((int)&info->u + 0x10);
        iVar2 = __gtsf2(uStack_18,uVar9);
        uVar6 = uVar9;
        if (0 < iVar2) {
          uVar6 = uStack_18;
          uStack_18 = uVar9;
        }
        uVar4 = __subsf3(uVar6,uStack_18);
        uVar6 = __ltsf2(*(undefined4 *)((int)&info->u + 8),uVar4);
        uVar6 = uVar6 >> 0x1f;
        goto _L0;
      }
    }
    uVar10 = *(uint32_t *)((int)&info->u + 0x14);
    uVar6 = *(uint *)((int)&info->u + 0x10);
    if (((int)uVar10 < attr_value.s24) || ((attr_value.u24 == uVar10 && (uVar6 < uStack_18)))) {
      uVar9 = uStack_18 - uVar6;
      uVar7 = (attr_value.u24 - uVar10) - (uint)(uStack_18 < uVar9);
    }
    else {
      uVar9 = uVar6 - uStack_18;
      uVar7 = (uVar10 - attr_value._0_4_) - (uint)(uVar6 < uVar9);
    }
    uVar5 = *(uint *)((int)&info->u + 0xc);
    uVar6 = 1;
    if ((int)uVar7 <= (int)uVar5) {
_L0:
      uVar6 = 1;
      if ((uVar5 != uVar7) || (uVar9 <= *(uint *)((int)&info->u + 8))) {
        uVar6 = 0;
      }
    }
  }
_L0:
  if (uVar6 == 0) {
    return 0;
  }
_L0:
  bVar1 = info->field_0x9;
  info->field_0x9 = bVar1 | 0x20;
  if ((9U >> (bVar1 & 0xf) & 1) != 0) {
    info->field_0x9 = bVar1 & 0xf0 | 0x23;
    process_attr_report(info);
  }
  return 0;
}

