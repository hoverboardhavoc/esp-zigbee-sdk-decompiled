/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> zcl_general_cmd.o -> zcl_report_attr_cmd_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int zcl_report_attr_cmd_req(int param_1)

{
  int iVar1;
  int iVar2;
  undefined2 *puVar3;
  uint uVar4;
  undefined4 uVar5;
  undefined2 uVar6;
  undefined2 uStack_4a;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  
  uStack_48 = 0;
  uStack_44 = 0;
  uStack_40 = 0;
  uStack_3c = 0;
  uStack_38 = 0;
  uStack_34 = 0;
  uStack_30 = 0;
  uStack_2c = 0;
  uStack_28 = 0;
  uStack_24 = 0;
  if (param_1 == 0) {
    iVar1 = -1;
  }
  else {
    iVar1 = zcl_packet_init(&uStack_48,*(uint *)(param_1 + 0x10) & 1);
    if (iVar1 == 0) {
      if ((*(byte *)(param_1 + 0x10) & 2) == 0) {
        uVar5 = 2;
      }
      else {
        uVar5 = 1;
      }
      if ((*(byte *)(param_1 + 0x10) & 1) == 0) {
        uVar6 = 0;
      }
      else {
        uVar6 = *(undefined2 *)(param_1 + 0xe);
      }
      uVar4 = *(uint *)(param_1 + 0x10);
      iVar1 = zcl_cmd_to_packet(&uStack_48,0,uVar4 & 1,uVar4 >> 1 & 1,uVar4 >> 2 & 1,
                                *(undefined2 *)(param_1 + 0xe),10,*(undefined2 *)(param_1 + 0xc));
      if (iVar1 == 0) {
        iVar2 = zcl_reporting_info_find
                          (*(undefined1 *)(param_1 + 0xb),*(undefined2 *)(param_1 + 0xc),uVar5,
                           *(undefined2 *)(param_1 + 0x1c),uVar6);
        if (iVar2 == 0) {
          iVar1 = 5;
        }
        else {
          iVar1 = zcl_get_attr_desc(*(undefined1 *)(iVar2 + 1),*(undefined2 *)(iVar2 + 4),
                                    *(undefined1 *)(iVar2 + 8),*(undefined2 *)(iVar2 + 6),
                                    *(undefined2 *)(iVar2 + 0x30));
          if (iVar1 == 0) {
            iVar1 = 5;
          }
          else if ((*(byte *)(iVar1 + 3) & 4) == 0) {
            iVar1 = 6;
          }
          else {
            iVar1 = zcl_attr_type_is_reportable(*(undefined1 *)(iVar1 + 2));
            if (iVar1 == 0) {
              iVar1 = 6;
            }
            else {
              for (; iVar2 != 0; iVar2 = zcl_reporting_find_next_ready_report(iVar2)) {
                puVar3 = (undefined2 *)
                         zcl_get_attr_desc(*(undefined1 *)(iVar2 + 1),*(undefined2 *)(iVar2 + 4),
                                           *(undefined1 *)(iVar2 + 8),*(undefined2 *)(iVar2 + 6),
                                           *(undefined2 *)(iVar2 + 0x30));
                zcl_reporting_sync_attr_change(iVar2);
                uStack_4a = *puVar3;
                iVar1 = zmsg_append_bytes(uStack_24,2,&uStack_4a);
                if (iVar1 != 0) goto _L0;
                uStack_4a = CONCAT11(uStack_4a._1_1_,*(undefined1 *)(puVar3 + 1));
                iVar1 = zmsg_append_bytes(uStack_24,1,&uStack_4a);
                if ((iVar1 != 0) ||
                   (iVar1 = zcl_packet_append_variable_attr_value
                                      (uStack_24,*(undefined1 *)(puVar3 + 1),
                                       *(undefined4 *)(puVar3 + 4)), iVar1 != 0)) goto _L0;
              }
              zcl_packet_send(&uStack_48,param_1 + 0x14);
              iVar1 = zcl_status_to_err();
_L0:
              if (iVar1 == 0) {
                return 0;
              }
            }
          }
        }
      }
    }
    else {
      iVar1 = -1;
    }
  }
  zcl_packet_free(&uStack_48);
  return iVar1;
}

