/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> zcl_general_cmd.o -> zcl_cmd_configure_reporting_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zcl_cmd_configure_reporting_handler(int param_1,int param_2)

{
  undefined1 uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  char *pcVar6;
  size_t __size;
  undefined4 uVar7;
  undefined4 unaff_s3;
  undefined2 uVar8;
  undefined2 uStack_44;
  ushort local_42;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  void *pvStack_34;
  
  uStack_40 = 0;
  uStack_3c = 0;
  uStack_38 = 0;
  pvStack_34 = (void *)0x0;
  if (param_1 == 0) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/zcl/zcl_general_cmd.c",0x239,
                  "zcl_cmd_configure_reporting_handler","packet");
  }
  else {
    unaff_s3 = *(undefined4 *)(param_1 + 0x24);
    if ((*(byte *)(param_1 + 0x1a) & 4) != 0) {
      uVar8 = *(undefined2 *)(param_1 + 0x1c);
      goto _L0;
    }
  }
  uVar8 = 0;
_L0:
  iVar2 = af_get_ep_desc(*(undefined1 *)(param_1 + 0x15));
  if (iVar2 == 0) {
    iVar2 = 0x81;
  }
  else {
    if ((*(byte *)(param_1 + 0x1a) & 8) == 0) {
      uVar7 = 1;
    }
    else {
      uVar7 = 2;
    }
    iVar3 = af_endpoint_get_cluster_desc(*(undefined2 *)(param_1 + 0x16),uVar7);
    if (iVar3 == 0) {
      iVar2 = 0xc3;
    }
    else {
      uVar4 = zmsg_get_length(unaff_s3);
      local_42 = 0;
      while (local_42 < uVar4) {
        uStack_40 = 0;
        uStack_3c = 0;
        uStack_38 = 0;
        pvStack_34 = (void *)0x0;
        af_read_le8(unaff_s3,&local_42);
        af_read_le16(unaff_s3,&local_42,(int)&uStack_40 + 2);
        if ((uStack_40 & 0xff) == 0) {
          af_read_le8(unaff_s3,&local_42,&uStack_3c);
          af_read_le16(unaff_s3,&local_42,(int)&uStack_3c + 2);
          af_read_le16(unaff_s3,&local_42,&uStack_38);
          iVar2 = zcl_attr_type_is_analog(uStack_3c & 0xff);
          if (iVar2 != 0) {
            __size = zcl_packet_read_variable_attr_size
                               (*(undefined4 *)(param_1 + 0x24),local_42,uStack_3c & 0xff);
            pvStack_34 = calloc(1,__size);
            zcl_packet_read_variable_attr_value(unaff_s3,&local_42,uStack_3c & 0xff,pvStack_34);
          }
        }
        else {
          af_read_le16(unaff_s3,&local_42,&uStack_3c);
        }
        if (uVar4 < local_42) {
          iVar2 = 0x80;
          goto _L0;
        }
        iVar2 = zcl_cluster_get_attr_desc(iVar3,uStack_40 >> 0x10,uVar8);
        iVar5 = check_configure_reporting_field(&uStack_40,iVar2);
        if (iVar5 == 0) {
          if ((*(byte *)(param_1 + 0x1a) & 8) == 0) {
            uVar7 = 1;
          }
          else {
            uVar7 = 2;
          }
          pcVar6 = (char *)zcl_reporting_info_find
                                     (*(undefined1 *)(param_1 + 0x15),
                                      *(undefined2 *)(param_1 + 0x16),uVar7,uStack_40 >> 0x10,
                                      *(undefined2 *)(iVar2 + 4));
          if (pcVar6 == (char *)0x0) {
            if ((*(byte *)(param_1 + 0x1a) & 8) == 0) {
              uVar7 = 1;
            }
            else {
              uVar7 = 2;
            }
            pcVar6 = (char *)zcl_reporting_info_create
                                       (*(undefined1 *)(param_1 + 0x15),
                                        *(undefined2 *)(param_1 + 0x18),(char)uStack_40 != '\0',
                                        *(undefined2 *)(param_1 + 0x16),uVar7,uStack_40 >> 0x10,
                                        *(undefined2 *)(iVar2 + 4));
            zcl_reporting_info_add();
            iVar5 = err_to_zcl_status();
          }
          else {
            iVar5 = 0;
          }
          iVar2 = 0;
          if (iVar5 != 0) goto _L0;
          if (*pcVar6 == '\0') {
            *(undefined2 *)(pcVar6 + 0x10) = uStack_3c._2_2_;
            *(undefined2 *)(pcVar6 + 0x12) = (undefined2)uStack_38;
            iVar2 = reportable_change_is_present(uStack_3c & 0xff);
            if (iVar2 != 0) {
              zcl_write_attr_value(pcVar6 + 0x18,pvStack_34,uStack_3c & 0xff);
            }
          }
          else {
            *(undefined2 *)(pcVar6 + 0x10) = (undefined2)uStack_3c;
          }
          zcl_reporting_info_update(pcVar6);
          uVar1 = err_to_zcl_status();
          uStack_44 = CONCAT11(uStack_44._1_1_,uVar1);
          zmsg_append_bytes(*(undefined4 *)(param_2 + 0x24),1,&uStack_44);
        }
        else {
          uStack_44._0_1_ = (char)iVar5;
          zmsg_append_bytes(*(undefined4 *)(param_2 + 0x24),1,&uStack_44);
          uStack_44 = CONCAT11(uStack_44._1_1_,(char)uStack_40);
          zmsg_append_bytes(*(undefined4 *)(param_2 + 0x24),1,&uStack_44);
          uStack_44 = uStack_40._2_2_;
          zmsg_append_bytes(*(undefined4 *)(param_2 + 0x24),2,&uStack_44);
        }
        if (pvStack_34 != (void *)0x0) {
          mm_free();
          pvStack_34 = (void *)0x0;
        }
      }
      iVar2 = 0;
    }
  }
_L0:
  if (pvStack_34 != (void *)0x0) {
    mm_free();
  }
  if (iVar2 == 0) {
    zcl_packet_setup_response(param_2,param_1,7);
  }
  else {
    zcl_packet_setup_default_response(param_2,param_1,iVar2);
  }
  return;
}

