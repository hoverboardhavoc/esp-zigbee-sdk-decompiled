/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_nwk_mgmt.o -> zdo_nwk_mgmt_nwk_update_req_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 zdo_nwk_mgmt_nwk_update_req_handler(int param_1,int param_2)

{
  ushort uVar1;
  uint uVar2;
  uint uVar3;
  byte bVar4;
  int iVar5;
  void *pvVar6;
  undefined4 uVar7;
  uint uVar8;
  uint uStack_6c;
  undefined4 uStack_68;
  uint uStack_64;
  code *pcStack_60;
  void *pvStack_5c;
  uint auStack_58 [10];
  byte bStack_2d;
  uint uStack_2c;
  uint uStack_28;
  undefined4 uStack_24;
  
  uStack_2c = 0;
  uStack_28 = 0;
  uStack_24 = 0;
  bStack_2d = 0xff;
  if (param_1 == 0) {
    uVar7 = 0xfe;
  }
  else if (*(int *)(param_1 + 0x14) == 0) {
    uVar7 = 0xfe;
  }
  else if (param_2 == 0) {
    uVar7 = 0xfe;
  }
  else {
    uVar1 = *(ushort *)(param_1 + 2);
    iVar5 = zdo_op_nwk_mgmt_nwk_update_req(&uStack_2c,0);
    uVar3 = uStack_2c;
    if (iVar5 == 0) {
      uVar8 = uStack_2c & 0x7ffffff;
      uVar2 = uStack_28 & 0xff;
      if (uVar2 == 0xfe) {
        iVar5 = core_globals_get();
        if ((*(int *)(iVar5 + 0xa30) == 0) ||
           (iVar5 = core_globals_get(), *(uint *)(iVar5 + 0xa30) == (uVar3 & 0x7ffffff))) {
          bVar4 = 0;
          for (uVar3 = uVar3 & 0x7ffffff; uVar3 != 0; uVar3 = uVar3 & uVar3 - 1) {
            bVar4 = bVar4 + 1;
          }
          if (bVar4 < 2) {
            bStack_2d = 0xff;
            channel_page_get_next_channel(uVar8,&bStack_2d);
            uStack_68 = 0;
            iVar5 = nwk_mm_get_pib_attr(0,99,&uStack_68,4);
            if ((iVar5 == 0) && (((uStack_68 & 0x7ffffff) >> (bStack_2d & 0x1f) & 1) != 0)) {
              auStack_58[0] = 1 << (bStack_2d & 0x1f) & 0x7ffffff;
              nwk_mm_set_pib_attr(0x61,auStack_58);
              return 0xfe;
            }
            uVar3 = 0x80;
          }
          else {
            uVar3 = 0x80;
          }
        }
        else {
          uVar3 = 0x8d;
        }
      }
      else {
        if (uVar2 == 0xff) {
          iVar5 = aps_secur_is_centralized();
          if ((iVar5 != 0) && ((short)uStack_24 != 0)) {
            return 0xfe;
          }
          iVar5 = core_globals_get();
          *(uint *)(iVar5 + 8) = uVar8;
          iVar5 = core_globals_get();
          *(short *)(iVar5 + 0x9dc) = (short)uStack_24;
          return 0xfe;
        }
        if (uVar2 < 6) {
          if (uVar1 < 0xfff8) {
            bStack_2d = 0xff;
            uStack_6c = 0;
            nwk_mm_get_pib_attr(0,99,&uStack_6c);
            if ((uVar3 & 0x7ffffff) == (uStack_6c & 0x7ffffff & uVar3 & 0x7ffffff)) {
              pvVar6 = calloc(1,0x18);
              if (pvVar6 == (void *)0x0) {
                uVar3 = 0x8a;
              }
              else {
                uVar3 = zdo_packet_move(param_2);
                uVar3 = uVar3 & 0xff;
                if (uVar3 == 0) {
                  uStack_68 = (uint)CONCAT21(uStack_68._2_2_,(undefined1)uStack_28) << 8;
                  uStack_64 = uStack_2c;
                  pcStack_60 = zdo_mgmt_ed_scan_handler;
                  auStack_58[0] = 0;
                  auStack_58[1] = 0;
                  auStack_58[2] = 0;
                  auStack_58[3] = 0;
                  auStack_58[4] = 0;
                  auStack_58[5] = 0;
                  auStack_58[6] = 0;
                  auStack_58[7] = 0;
                  auStack_58[8] = 0;
                  auStack_58[9] = 0;
                  pvStack_5c = pvVar6;
                  zmsg_add_footer(*(undefined4 *)((int)pvVar6 + 0x14),auStack_58,0x28);
                  nwk_nlme_scan(&uStack_68);
                  uVar3 = ezb_err_to_zdp_status();
                  if (uVar3 == 0) {
                    return 0xfe;
                  }
                  mm_free(pvVar6);
                }
                else {
                  mm_free(pvVar6);
                }
                if (uVar3 == 0xfe) {
                  return 0xfe;
                }
              }
            }
            else {
              uVar3 = 0x86;
            }
          }
          else {
            uVar3 = 0x80;
          }
        }
        else {
          uVar3 = 0x80;
        }
      }
      auStack_58[1] = 0;
      auStack_58[2] = 0;
      auStack_58[3] = 0;
      auStack_58[4] = 0;
      auStack_58[5] = 0;
      auStack_58[6] = 0;
      auStack_58[7] = 0;
      auStack_58[8] = 0;
      auStack_58[9] = 0;
      auStack_58[0] = uVar3 & 0xff;
      uVar7 = zdo_op_nwk_mgmt_nwk_update_notify(*(undefined4 *)(param_2 + 0x14),auStack_58,1);
    }
    else {
      uVar7 = 0xfe;
    }
  }
  return uVar7;
}

