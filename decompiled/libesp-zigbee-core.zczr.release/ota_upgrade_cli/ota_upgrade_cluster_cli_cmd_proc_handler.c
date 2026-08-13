/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-core.zczr.release -> ota_upgrade_cli.o -> ota_upgrade_cluster_cli_cmd_proc_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int ota_upgrade_cluster_cli_cmd_proc_handler(int param_1)

{
  byte bVar1;
  ushort uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  short sVar8;
  ushort uStack_66;
  undefined4 uStack_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  uint uStack_58;
  uint uStack_54;
  byte abStack_50 [4];
  void *pvStack_4c;
  undefined1 auStack_48 [32];
  char cStack_28;
  undefined4 uStack_24;
  
  memset(auStack_48,0,0x28);
  if (param_1 == 0) {
    return 1;
  }
  if ((*(byte *)(param_1 + 0x1a) & 8) == 0) {
    return 1;
  }
  iVar3 = zcl_packet_init(auStack_48,*(byte *)(param_1 + 0x1a) >> 2 & 1);
  if (iVar3 != 0) {
    return iVar3;
  }
  bVar1 = *(byte *)(param_1 + 0x20);
  if (bVar1 == 5) {
    uStack_64 = (uint)uStack_64._2_2_ << 0x10;
    memset(&uStack_60,0,0x18);
    iVar3 = ota_upgrade_downloading_context_get(*(undefined1 *)(param_1 + 0x15));
    if ((iVar3 == 0) || (**(char **)(iVar3 + 0x18) != '\x01')) {
_L0:
      uVar6 = 0xfe;
    }
    else {
      uVar5 = zmsg_get_length(*(undefined4 *)(param_1 + 0x24));
      af_read_le8_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_64,&uStack_60);
      if ((uStack_60 & 0xff) == 0) {
        af_read_le16_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_64,&uStack_5c);
        af_read_le16_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_64,(int)&uStack_5c + 2);
        af_read_le32_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_64,&uStack_58);
        af_read_le32_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_64,&uStack_54);
        af_read_le8_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_64,abStack_50);
        uVar7 = (uint)abStack_50[0];
        pvStack_4c = calloc(1,uVar7);
        if ((pvStack_4c != (void *)0x0) || (uVar6 = 0x89, uVar7 == 0)) {
          sVar8 = (short)uStack_64;
          iVar4 = zmsg_read_bytes(*(undefined4 *)(param_1 + 0x24),uStack_64 & 0xffff,uVar7,
                                  pvStack_4c);
          if ((iVar4 == 0) && (uVar7 != 0)) {
            sVar8 = -1;
          }
          else {
            sVar8 = sVar8 + (short)iVar4;
          }
          uStack_64 = CONCAT22(uStack_64._2_2_,sVar8);
          goto _L0;
        }
      }
      else {
        if ((uStack_60 & 0xff) == 0x97) {
          af_read_le32_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_64,&uStack_5c);
          af_read_le32_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_64,&uStack_58);
          af_read_le16_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_64,&uStack_54);
        }
_L0:
        uVar6 = 0x80;
        if ((uStack_64 & 0xffff) <= uVar5) {
          ota_upgrade_download_stop_retry(iVar3,3);
          if ((uStack_60 & 0xff) == 0) {
            if (((**(short **)(iVar3 + 0x1c) != (short)uStack_5c) ||
                (**(short **)(iVar3 + 0x20) != uStack_5c._2_2_)) ||
               (*(uint *)(iVar3 + 0x2c) != uStack_58)) goto _L0;
            uVar5 = *(uint *)(iVar3 + 0x28);
            uVar7 = (uint)abStack_50[0] + **(int **)(iVar3 + 4);
            if ((uVar5 == 0) || (uVar7 < uVar5)) {
              **(undefined1 **)(iVar3 + 0x18) = 1;
              **(uint **)(iVar3 + 4) = uVar7;
              *(uint *)(iVar3 + 0x2c) = uStack_58;
              *(uint *)(iVar3 + 0x28) = uVar5;
              uVar6 = ota_upgrade_setup_image_block_request(auStack_48,iVar3,param_1);
            }
            else {
              **(undefined1 **)(iVar3 + 0x18) = 2;
              if (*(undefined4 **)(iVar3 + 0x10) != (undefined4 *)0x0) {
                **(undefined4 **)(iVar3 + 0x10) = *(undefined4 *)(iVar3 + 0x2c);
              }
              uVar6 = ota_upgrade_setup_upgrade_end_request(auStack_48,iVar3,param_1,0);
            }
            if ((uVar6 == 0) &&
               (zcl_message_ota_upgrade_downloading_progress(param_1,1,&uStack_60),
               **(char **)(iVar3 + 0x18) == '\x02')) {
              zcl_message_ota_upgrade_downloading_progress(param_1,3,&uStack_60);
            }
          }
          else {
            uVar6 = 0x95;
            if ((uStack_60 & 0xff) == 0x97) {
              uVar6 = 0x85;
            }
          }
        }
      }
    }
    if (pvStack_4c != (void *)0x0) {
      mm_free();
    }
joined_r0x00010a5a:
    if (uVar6 == 0) goto _L0;
_L0:
    iVar3 = zcl_packet_setup_default_response(auStack_48,param_1,uVar6);
  }
  else {
    if (5 < bVar1) {
      if (bVar1 != 7) {
_L0:
        uVar6 = 0x81;
        goto _L0;
      }
      uStack_64 = (uint)uStack_64._2_2_ << 0x10;
      uStack_60 = 0;
      uStack_5c = 0;
      uStack_58 = 0;
      uStack_54 = 0;
      iVar3 = ota_upgrade_downloading_context_get(*(undefined1 *)(param_1 + 0x15));
      if ((iVar3 == 0) || (**(char **)(iVar3 + 0x18) != '\x02')) {
_L0:
        uVar6 = 0xfe;
        goto _L0;
      }
      uVar5 = zmsg_get_length(*(undefined4 *)(param_1 + 0x24));
      af_read_le16_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_64,&uStack_60);
      af_read_le16_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_64,(int)&uStack_60 + 2);
      af_read_le32_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_64,&uStack_5c);
      af_read_le32_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_64,&uStack_58);
      af_read_le32_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_64,&uStack_54);
      uVar6 = 0x80;
      if (uVar5 < (uStack_64 & 0xffff)) goto _L0;
      ota_upgrade_download_stop_retry(iVar3,6,0x80);
      if ((((((uint)**(ushort **)(iVar3 + 0x1c) != (uStack_60 & 0xffff)) &&
            ((uStack_60 & 0xffff) != 0xffff)) ||
           ((**(short **)(iVar3 + 0x20) != uStack_60._2_2_ && (uStack_60._2_2_ != -1)))) ||
          ((*(uint *)(iVar3 + 0x2c) != uStack_5c && (uStack_5c != 0xffffffff)))) ||
         ((uStack_54 != 0xffffffff && (uStack_54 < uStack_58)))) goto _L0;
      **(undefined4 **)(iVar3 + 4) = 0;
      memset((void *)(iVar3 + 0x28),0,8);
      if (uStack_54 == 0xffffffff) {
        **(undefined1 **)(iVar3 + 0x18) = 3;
        goto _L0;
      }
      iVar4 = zcl_message_ota_upgrade_downloading_progress(param_1,4,&uStack_60);
      if (iVar4 == 0x96) {
        ota_upgrade_set_upgrade_status_normal(iVar3,0x96);
      }
      else {
        if (iVar4 != 0x99) {
          if (iVar4 == 0) {
            **(undefined1 **)(iVar3 + 0x18) = 4;
            zcl_message_ota_upgrade_downloading_progress(param_1,5,&uStack_60);
            ota_upgrade_set_upgrade_status_normal(iVar3);
            goto _L0;
          }
          ota_upgrade_set_upgrade_status_normal(iVar3);
          goto _L0;
        }
        **(undefined1 **)(iVar3 + 0x18) = 5;
      }
      uVar6 = ota_upgrade_setup_upgrade_end_request(auStack_48,iVar3,param_1,iVar4);
      goto joined_r0x00010a5a;
    }
    if (bVar1 == 0) {
      uStack_60 = 0xffff0000;
      uStack_5c = 0xffff;
      uStack_58 = 0xffffffff;
      uStack_66 = 0;
      iVar4 = ota_upgrade_downloading_context_get(*(undefined1 *)(param_1 + 0x15));
      uVar6 = 0x95;
      if (**(char **)(iVar4 + 0x18) == '\0') {
        uVar5 = zmsg_get_length(*(undefined4 *)(param_1 + 0x24),0x95);
        af_read_le8_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_66,&uStack_60);
        uVar6 = 0x85;
        if ((uStack_60 & 0xff) < 4) {
          af_read_le8_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_66,(int)&uStack_60 + 1);
          if ((((uStack_60 & 0xff) != 0) &&
              (af_read_le16_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_66,(int)&uStack_60 + 2),
              1 < (uStack_60 & 0xff))) &&
             (af_read_le16_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_66,&uStack_5c),
             2 < (uStack_60 & 0xff))) {
            af_read_le32_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_66,&uStack_58);
          }
          uVar6 = 0x80;
          if (uStack_66 <= uVar5) {
            uVar2 = *(ushort *)(param_1 + 0xc);
            if (uVar2 < 0xfff8) {
              uVar5 = nwk_get_short_address(0x80);
              if (uVar2 != uVar5) goto _L0;
_L0:
              uVar5 = random_noncrypto_get_u32();
              if (uVar5 % 100 <= (uStack_60 >> 8 & 0xff)) {
                iVar3 = zcl_packet_setup_response_with_extension(auStack_48,param_1,1,0);
                if (iVar3 == 0) {
                  uStack_64 = uStack_64 & 0xffffff00;
                  iVar3 = zmsg_append_bytes(uStack_24,1,&uStack_64);
                  if (((iVar3 == 0) &&
                      (iVar3 = zmsg_append_le16(uStack_24,**(undefined2 **)(iVar4 + 0x1c)),
                      iVar3 == 0)) &&
                     (iVar3 = zmsg_append_le16(uStack_24,**(undefined2 **)(iVar4 + 0x20)),
                     iVar3 == 0)) {
                    uStack_64 = 0xffffffff;
                    if (*(uint **)(iVar4 + 8) != (uint *)0x0) {
                      uStack_64 = **(uint **)(iVar4 + 8);
                    }
                    iVar3 = zmsg_append_bytes(uStack_24,4,&uStack_64);
                    if (iVar3 == 0) goto _L0;
                  }
                  iVar3 = 0x89;
                }
                goto _L0;
              }
              goto _L0;
            }
            uVar5 = uStack_60 & 0xff;
            if (uVar5 == 2) {
_L0:
              if (((uint)**(ushort **)(iVar4 + 0x20) == (uStack_5c & 0xffff)) ||
                 ((uStack_5c & 0xffff) == 0xffff)) {
_L0:
                if ((**(short **)(iVar4 + 0x1c) == uStack_60._2_2_) || (uStack_60._2_2_ == -1))
                goto _L0;
              }
            }
            else {
              if (uVar5 < 3) {
                if (uVar5 == 0) goto _L0;
                goto _L0;
              }
              if (uVar5 == 3) {
                uVar5 = 0xffffffff;
                if (*(uint **)(iVar4 + 8) != (uint *)0x0) {
                  uVar5 = **(uint **)(iVar4 + 8);
                }
                uVar7 = 0xffffffff;
                if (*(uint **)(iVar4 + 0x10) != (uint *)0x0) {
                  uVar7 = **(uint **)(iVar4 + 0x10);
                }
                if ((uStack_58 != uVar5) && (uStack_58 != uVar7)) goto _L0;
              }
            }
_L0:
            uVar6 = 0x96;
          }
        }
      }
      goto _L0;
    }
    if (bVar1 != 2) goto _L0;
    uStack_64 = (uint)uStack_64._2_2_ << 0x10;
    uStack_60 = 0;
    uStack_5c = 0;
    uStack_58 = 0;
    uStack_54 = 0;
    iVar3 = ota_upgrade_downloading_context_get(*(undefined1 *)(param_1 + 0x15));
    if (iVar3 == 0) goto _L0;
    uVar6 = 0x95;
    if (**(char **)(iVar3 + 0x18) != '\0') goto _L0;
    uVar5 = zmsg_get_length(*(undefined4 *)(param_1 + 0x24));
    af_read_le8_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_64,&uStack_60);
    if ((uStack_60 & 0xff) == 0) {
      af_read_le16_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_64,(int)&uStack_60 + 2);
      af_read_le16_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_64,&uStack_5c);
      af_read_le32_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_64,&uStack_58);
      af_read_le32_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_64,&uStack_54);
    }
    uVar6 = 0x80;
    if (uVar5 < (uStack_64 & 0xffff)) goto _L0;
    ota_upgrade_download_stop_retry(iVar3,1);
    uVar6 = zcl_message_ota_upgrade_query_next_image(param_1,&uStack_60);
    if (uVar6 != 0) goto _L0;
    uVar6 = uStack_60 & 0xff;
    if (uVar6 != 0) {
      if ((uVar6 == 0x7e) || (uVar6 == 0x98)) {
        ota_upgrade_set_upgrade_status_normal(iVar3);
      }
      else {
_L0:
        uVar6 = 0xfe;
      }
      goto _L0;
    }
    if ((**(short **)(iVar3 + 0x1c) != uStack_60._2_2_) ||
       (**(short **)(iVar3 + 0x20) != (short)uStack_5c)) {
      uVar6 = 0x96;
      goto _L0;
    }
    if (((*(uint **)(iVar3 + 8) != (uint *)0x0) && (**(uint **)(iVar3 + 8) == uStack_58)) ||
       ((*(uint **)(iVar3 + 0x10) != (uint *)0x0 && (**(uint **)(iVar3 + 0x10) == uStack_58))))
    goto _L0;
    **(undefined1 **)(iVar3 + 0x18) = 1;
    **(undefined4 **)(iVar3 + 4) = 0;
    *(uint *)(iVar3 + 0x2c) = uStack_58;
    *(uint *)(iVar3 + 0x28) = uStack_54;
    zcl_message_ota_upgrade_downloading_progress(param_1,0,&uStack_60);
    iVar3 = ota_upgrade_setup_image_block_request(auStack_48,iVar3,param_1);
  }
  if (iVar3 != 0) {
_L0:
    zcl_packet_free(auStack_48);
    return iVar3;
  }
_L0:
  if (cStack_28 == '\v') {
    zcl_packet_send(auStack_48,0);
  }
  else {
    ota_upgrade_packet_send(auStack_48);
  }
  return 0;
}

