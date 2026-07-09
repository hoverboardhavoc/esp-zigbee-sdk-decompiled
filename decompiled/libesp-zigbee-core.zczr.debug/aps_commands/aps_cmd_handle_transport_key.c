/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> aps_commands.o -> aps_cmd_handle_transport_key
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void aps_cmd_handle_transport_key(short *param_1,int param_2)

{
  short sVar1;
  short sVar2;
  int iVar3;
  int iVar4;
  uint *puVar5;
  uint uVar6;
  undefined1 uVar7;
  uint uVar8;
  undefined1 *puStack_7c;
  uint uStack_78;
  uint uStack_74;
  uint uStack_70;
  uint uStack_6c;
  undefined1 auStack_67 [15];
  undefined4 uStack_58;
  uint uStack_54;
  uint uStack_50;
  uint uStack_4c;
  ushort uStack_48;
  uint uStack_44;
  uint uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  uint uStack_28;
  undefined2 uStack_24;
  byte bStack_22;
  
  iVar3 = aps_secur_is_tc();
  uVar7 = (undefined1)iVar3;
  if ((iVar3 == 0) &&
     ((iVar3 = core_globals_get(), -1 < *(char *)(iVar3 + 0x9ba) ||
      ((*(ushort *)(param_2 + 0x16) & 4) != 0)))) {
    uStack_44 = 0;
    uStack_40 = 0;
    uStack_3c = 0;
    uStack_38 = 0;
    uStack_34 = 0;
    uStack_30 = 0;
    uStack_2c = 0;
    uStack_28 = 0;
    uStack_24 = 0;
    bStack_22 = 0;
    sVar1 = zmsg_get_offset(param_2);
    sVar2 = zmsg_read_bytes(param_2,sVar1 + 1,1,&uStack_3c);
    uVar6 = uStack_3c & 0xff;
    if (uVar6 == 3) {
      iVar3 = 0x19;
    }
    else if (uVar6 == 4) {
      iVar3 = 0x20;
    }
    else if (uVar6 == 1) {
      iVar3 = 0x21;
    }
    else {
      iVar3 = 0;
    }
    iVar4 = zmsg_read_bytes(param_2,sVar1 + 1 + sVar2,iVar3,auStack_67);
    if (iVar4 == iVar3) {
      bStack_22 = bStack_22 & 0xfe | (*(ushort *)(param_2 + 0x16) & 4) != 0;
      memcpy((void *)((int)&uStack_3c + 1),auStack_67,0x10);
      uVar6 = uStack_3c & 0xff;
      if (uVar6 == 3) {
        iVar3 = nwk_address_extended_by_short(*param_1,&uStack_44);
        if ((iVar3 == 0) && (iVar3 = aps_secur_is_addr_tc(&uStack_44), iVar3 != 0)) {
          uStack_2c._0_2_ = CONCAT11((char)(uStack_58 >> 8),(undefined1)uStack_2c);
          uStack_2c = CONCAT13((char)(uStack_58 >> 0x18),
                               CONCAT12((char)(uStack_58 >> 0x10),(undefined2)uStack_2c));
          uStack_28 = uStack_54;
          if ((uStack_50 >> 8 & 0xff) != 0) {
            uVar7 = (undefined1)iVar3;
          }
          uStack_24 = CONCAT11(uVar7,(char)uStack_50);
_L0:
          zmsg_free(param_2);
          apsme_transport_key_indication(&uStack_44);
          return;
        }
      }
      else if (uVar6 == 4) {
        uVar6 = uStack_54 << 0x18 | uStack_58 >> 8;
        uVar8 = uStack_50 << 0x18 | uStack_54 >> 8;
        uStack_70 = uStack_4c << 0x18 | uStack_50 >> 8;
        uStack_6c = (uint)(byte)uStack_48 << 0x18 | uStack_4c >> 8;
        uStack_78 = uVar6;
        uStack_74 = uVar8;
        iVar3 = aps_secur_is_addr_tc(&uStack_70);
        if (iVar3 != 0) {
          puVar5 = (uint *)nwk_get_extended_address();
          if ((uVar6 == *puVar5) && (uVar8 == puVar5[1])) {
            uStack_44 = uStack_70;
            uStack_40 = uStack_6c;
            goto _L0;
          }
        }
      }
      else if (uVar6 == 1) {
        uVar6 = uStack_54 << 0x10 | uStack_58 >> 0x10;
        uVar8 = uStack_50 << 0x10 | uStack_54 >> 0x10;
        uStack_70 = uStack_4c << 0x10 | uStack_50 >> 0x10;
        uStack_6c = (uint)uStack_48 << 0x10 | uStack_4c >> 0x10;
        uStack_78 = uVar6;
        uStack_74 = uVar8;
        iVar3 = aps_secur_is_centralized();
        if (iVar3 == 0) {
          if ((uStack_70 & uStack_6c) != 0xffffffff) goto _L0;
        }
        else if ((uStack_70 == 0 && uStack_6c == 0) ||
                ((uStack_70 == 0xffffffff && (uStack_6c == 0xffffffff)))) goto _L0;
        puVar5 = (uint *)nwk_get_extended_address();
        if ((uVar6 != *puVar5) || (uVar8 != puVar5[1])) {
          if ((ushort)param_1[1] < 0xfff8) {
            return;
          }
          if (uVar6 != 0 || uVar8 != 0) {
            return;
          }
        }
        aps_secur_set_tc_address(&uStack_70);
        if ((uStack_70 != 0xffffffff) || (uStack_6c != 0xffffffff)) {
          iVar3 = nwk_address_update(&uStack_70,0,&puStack_7c);
          if (iVar3 != 0) goto _L0;
          iVar3 = nwk_is_device_zr();
          if ((iVar3 != 0) && (*param_1 != 0)) {
            nwk_route_table_add_rev_route(0,0);
          }
        }
        if ((*(ushort *)(param_2 + 0x16) & 4) != 0) {
          zmsg_get_footer(param_2,&puStack_7c);
          iVar3 = aps_secur_is_centralized();
          if (iVar3 == 0) {
            aps_secur_delete_key_pair(puStack_7c);
          }
          else {
            *puStack_7c = (char)uStack_70;
            puStack_7c[1] = (char)(uStack_70 >> 8);
            puStack_7c[2] = (char)(uStack_70 >> 0x10);
            puStack_7c[3] = (char)(uStack_70 >> 0x18);
            puStack_7c[4] = (char)uStack_6c;
            puStack_7c[5] = (char)(uStack_6c >> 8);
            puStack_7c[6] = (char)(uStack_6c >> 0x10);
            puStack_7c[7] = (char)(uStack_6c >> 0x18);
          }
        }
        uStack_2c._0_2_ = CONCAT11(uStack_58._1_1_,(undefined1)uStack_2c);
        uStack_44 = uStack_70;
        uStack_40 = uStack_6c;
        goto _L0;
      }
    }
  }
_L0:
  if (param_2 != 0) {
    zmsg_free(param_2);
  }
  return;
}

