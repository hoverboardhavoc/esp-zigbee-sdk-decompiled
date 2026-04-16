/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> zcl_reporting.o -> check_attr_delta
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Variable defined which should be unmapped: attr_value */
/* WARNING: Unknown calling convention */

_Bool check_attr_delta(zcl_reporting_info_t *info)

{
  byte bVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint32_t uVar9;
  bool bVar10;
  uint uStack_18;
  zcl_attr_variable_t attr_value;
  
  if (info == (zcl_reporting_info_t *)0x0) {
    bVar10 = false;
  }
  else {
    iVar4 = zcl_get_attr_desc(info->ep_id,info->cluster_id,info->cluster_role,info->attr_id,
                              info->manuf_code);
    if (iVar4 == 0) {
      bVar10 = false;
    }
    else {
      uVar8 = *(uint *)&info->cluster_role >> 0xc;
      if ((uVar8 & 1) == 0) {
        iVar5 = zcl_attr_type_is_analog(*(undefined1 *)(iVar4 + 2));
        if (iVar5 == 0) {
          iVar5 = zcl_get_attr_value_size(*(undefined1 *)(iVar4 + 2),*(undefined4 *)(iVar4 + 8));
          bVar10 = false;
          if ((iVar5 != 0xff) &&
             (iVar2 = *(int *)((int)&info->u + 0x10),
             iVar4 = crc32_next(0,*(undefined4 *)(iVar4 + 8),iVar5), iVar2 != iVar4)) {
            bVar10 = true;
          }
        }
        else {
          zcl_read_attr_value(&uStack_18,*(undefined4 *)(iVar4 + 8),*(undefined1 *)(iVar4 + 2));
          bVar1 = *(byte *)(iVar4 + 2);
          if (bVar1 == 0x28) {
            iVar4 = (int)(char)uStack_18;
            iVar5 = (int)*(char *)((int)&info->u + 0x10);
            if (iVar5 < iVar4) {
              iVar4 = iVar4 - iVar5;
            }
            else {
              iVar4 = iVar5 - iVar4;
            }
            bVar10 = *(char *)((int)&info->u + 8) < iVar4;
          }
          else if (bVar1 < 0x29) {
            if (bVar1 == 0x23) {
              uVar8 = *(uint *)((int)&info->u + 0x10);
              if (uVar8 < uStack_18) {
                uStack_18 = uStack_18 - uVar8;
              }
              else {
                uStack_18 = uVar8 - uStack_18;
              }
              bVar10 = *(uint *)((int)&info->u + 8) < uStack_18;
            }
            else if (bVar1 < 0x24) {
              if (bVar1 == 0x21) {
                uStack_18 = uStack_18 & 0xffff;
                uVar8 = (uint)*(ushort *)((int)&info->u + 0x10);
                if (uVar8 < uStack_18) {
                  iVar4 = uStack_18 - uVar8;
                }
                else {
                  iVar4 = uVar8 - uStack_18;
                }
                bVar10 = (int)(uint)*(ushort *)((int)&info->u + 8) < iVar4;
              }
              else if (bVar1 == 0x22) {
                uVar8 = *(uint *)((int)&info->u + 0x10);
                if (uVar8 < uStack_18) {
                  uStack_18 = uStack_18 - uVar8;
                }
                else {
                  uStack_18 = uVar8 - uStack_18;
                }
                bVar10 = *(uint *)((int)&info->u + 8) < uStack_18;
              }
              else if (bVar1 == 0x20) {
                uStack_18 = uStack_18 & 0xff;
                uVar8 = (uint)*(byte *)((int)&info->u + 0x10);
                if (uVar8 < uStack_18) {
                  iVar4 = uStack_18 - uVar8;
                }
                else {
                  iVar4 = uVar8 - uStack_18;
                }
                bVar10 = (int)(uint)*(byte *)((int)&info->u + 8) < iVar4;
              }
              else {
                bVar10 = false;
              }
            }
            else if (bVar1 == 0x25) {
              uVar8 = *(uint *)((int)&info->u + 0x10);
              uVar7 = *(uint *)((int)&info->u + 0x14);
              if ((uVar7 < attr_value.u24) || ((attr_value.u24 == uVar7 && (uVar8 < uStack_18)))) {
                uVar6 = uStack_18 - uVar8;
                uVar8 = (attr_value.u24 - uVar7) - (uint)(uStack_18 < uVar6);
              }
              else {
                uVar6 = uVar8 - uStack_18;
                uVar8 = (uVar7 - attr_value._0_4_) - (uint)(uVar8 < uVar6);
              }
              uVar7 = *(uint *)((int)&info->u + 0xc);
              bVar10 = true;
              if ((uVar8 <= uVar7) && ((uVar8 != uVar7 || (uVar6 <= *(uint *)((int)&info->u + 8)))))
              {
                bVar10 = false;
              }
            }
            else if (bVar1 == 0x27) {
              uVar8 = *(uint *)((int)&info->u + 0x10);
              uVar7 = *(uint *)((int)&info->u + 0x14);
              if ((uVar7 < attr_value.u24) || ((attr_value.u24 == uVar7 && (uVar8 < uStack_18)))) {
                uVar6 = uStack_18 - uVar8;
                uVar8 = (attr_value.u24 - uVar7) - (uint)(uStack_18 < uVar6);
              }
              else {
                uVar6 = uVar8 - uStack_18;
                uVar8 = (uVar7 - attr_value._0_4_) - (uint)(uVar8 < uVar6);
              }
              uVar7 = *(uint *)((int)&info->u + 0xc);
              bVar10 = true;
              if ((uVar8 <= uVar7) && ((uVar8 != uVar7 || (uVar6 <= *(uint *)((int)&info->u + 8)))))
              {
                bVar10 = false;
              }
            }
            else {
              bVar10 = false;
            }
          }
          else if (bVar1 == 0x2d) {
            uVar8 = *(uint *)((int)&info->u + 0x10);
            uVar9 = *(uint32_t *)((int)&info->u + 0x14);
            if (((int)uVar9 < attr_value.s24) || ((attr_value.u24 == uVar9 && (uVar8 < uStack_18))))
            {
              uVar7 = uStack_18 - uVar8;
              iVar4 = (attr_value.u24 - uVar9) - (uint)(uStack_18 < uVar7);
            }
            else {
              uVar7 = uVar8 - uStack_18;
              iVar4 = (uVar9 - attr_value._0_4_) - (uint)(uVar8 < uVar7);
            }
            iVar5 = *(int *)((int)&info->u + 0xc);
            bVar10 = true;
            if ((iVar4 <= iVar5) && ((iVar4 != iVar5 || (uVar7 <= *(uint *)((int)&info->u + 8))))) {
              bVar10 = false;
            }
          }
          else if (bVar1 < 0x2e) {
            if (bVar1 == 0x2a) {
              iVar4 = *(int *)((int)&info->u + 0x10);
              if (iVar4 < (int)uStack_18) {
                iVar4 = uStack_18 - iVar4;
              }
              else {
                iVar4 = iVar4 - uStack_18;
              }
              bVar10 = *(int *)((int)&info->u + 8) < iVar4;
            }
            else if (bVar1 == 0x2b) {
              iVar4 = *(int *)((int)&info->u + 0x10);
              if (iVar4 < (int)uStack_18) {
                iVar4 = uStack_18 - iVar4;
              }
              else {
                iVar4 = iVar4 - uStack_18;
              }
              bVar10 = *(int *)((int)&info->u + 8) < iVar4;
            }
            else if (bVar1 == 0x29) {
              iVar4 = (int)(short)uStack_18;
              iVar5 = (int)*(short *)((int)&info->u + 0x10);
              if (iVar5 < iVar4) {
                iVar4 = iVar4 - iVar5;
              }
              else {
                iVar4 = iVar5 - iVar4;
              }
              bVar10 = *(short *)((int)&info->u + 8) < iVar4;
            }
            else {
              bVar10 = false;
            }
          }
          else if (bVar1 == 0x2f) {
            uVar8 = *(uint *)((int)&info->u + 0x10);
            uVar9 = *(uint32_t *)((int)&info->u + 0x14);
            if (((int)uVar9 < attr_value.s24) || ((attr_value.u24 == uVar9 && (uVar8 < uStack_18))))
            {
              uVar7 = uStack_18 - uVar8;
              iVar4 = (attr_value.u24 - uVar9) - (uint)(uStack_18 < uVar7);
            }
            else {
              uVar7 = uVar8 - uStack_18;
              iVar4 = (uVar9 - attr_value._0_4_) - (uint)(uVar8 < uVar7);
            }
            iVar5 = *(int *)((int)&info->u + 0xc);
            bVar10 = true;
            if ((iVar4 <= iVar5) && ((iVar4 != iVar5 || (uVar7 <= *(uint *)((int)&info->u + 8))))) {
              bVar10 = false;
            }
          }
          else if (bVar1 == 0x39) {
            uVar3 = *(undefined4 *)((int)&info->u + 0x10);
            iVar4 = __gtsf2(uStack_18,uVar3);
            if (iVar4 < 1) {
              uVar3 = __subsf3(uVar3,uStack_18);
            }
            else {
              uVar3 = __subsf3(uStack_18,uVar3);
            }
            iVar4 = __ltsf2(*(undefined4 *)((int)&info->u + 8),uVar3);
            bVar10 = iVar4 < 0;
          }
          else {
            bVar10 = false;
          }
        }
      }
      else {
        info->field_0x9 = info->field_0x9 & 0xf | (byte)((uVar8 & 0xe) << 4);
        bVar10 = true;
      }
    }
  }
  return bVar10;
}

