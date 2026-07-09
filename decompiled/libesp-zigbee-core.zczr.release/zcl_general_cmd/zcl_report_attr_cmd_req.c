/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> zcl_general_cmd.o -> zcl_report_attr_cmd_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int zcl_report_attr_cmd_req(void *param_1)

{
  byte bVar1;
  ushort uVar2;
  int iVar3;
  int iVar4;
  undefined2 *puVar5;
  uint uVar6;
  undefined1 auStack_60 [24];
  undefined1 auStack_48 [36];
  undefined4 uStack_24;
  
  memset(auStack_48,0,0x28);
  if ((param_1 == (void *)0x0) ||
     (iVar3 = zcl_packet_init(auStack_48,*(uint *)((int)param_1 + 0x10) & 1), iVar3 != 0)) {
    iVar3 = -1;
  }
  else {
    bVar1 = *(byte *)((int)param_1 + 0x10);
    uVar2 = *(ushort *)((int)param_1 + 0xe);
    memcpy(auStack_60,param_1,10);
    uVar6 = *(uint *)((int)param_1 + 0x10);
    iVar3 = zcl_cmd_to_packet(auStack_48,0,uVar6 & 1,uVar6 >> 1 & 1,uVar6 >> 2 & 1,uVar2,10,
                              *(undefined2 *)((int)param_1 + 0xc));
    if (iVar3 == 0) {
      iVar4 = zcl_reporting_info_find
                        (*(undefined1 *)((int)param_1 + 0xb),*(undefined2 *)((int)param_1 + 0xc),
                         ((bVar1 & 2) == 0) + '\x01',*(undefined2 *)((int)param_1 + 0x1c),
                         -(bVar1 & 1) & uVar2);
      if ((iVar4 == 0) ||
         (iVar3 = zcl_get_attr_desc(*(undefined1 *)(iVar4 + 1),*(undefined2 *)(iVar4 + 4),
                                    *(undefined1 *)(iVar4 + 8),*(undefined2 *)(iVar4 + 6),
                                    *(undefined2 *)(iVar4 + 0x30)), iVar3 == 0)) {
        iVar3 = 5;
      }
      else if (((*(byte *)(iVar3 + 3) & 4) == 0) ||
              (iVar3 = zcl_attr_type_is_reportable(*(undefined1 *)(iVar3 + 2)), iVar3 == 0)) {
        iVar3 = 6;
      }
      else {
        do {
          puVar5 = (undefined2 *)
                   zcl_get_attr_desc(*(undefined1 *)(iVar4 + 1),*(undefined2 *)(iVar4 + 4),
                                     *(undefined1 *)(iVar4 + 8),*(undefined2 *)(iVar4 + 6),
                                     *(undefined2 *)(iVar4 + 0x30));
          zcl_reporting_sync_attr_change(iVar4);
          iVar3 = zmsg_append_le16(uStack_24,*puVar5);
          if (((iVar3 != 0) ||
              (iVar3 = zmsg_append_u8(uStack_24,*(undefined1 *)(puVar5 + 1)), iVar3 != 0)) ||
             (iVar3 = zcl_packet_append_variable_attr_value
                                (uStack_24,*(undefined1 *)(puVar5 + 1),*(undefined4 *)(puVar5 + 4)),
             iVar3 != 0)) goto _L0;
          iVar4 = zcl_reporting_find_next_ready_report(iVar4);
        } while (iVar4 != 0);
        zcl_packet_send(auStack_48,(int)param_1 + 0x14);
        iVar3 = zcl_status_to_err();
        if (iVar3 == 0) {
          return 0;
        }
      }
    }
  }
_L0:
  zcl_packet_free(auStack_48);
  return iVar3;
}

