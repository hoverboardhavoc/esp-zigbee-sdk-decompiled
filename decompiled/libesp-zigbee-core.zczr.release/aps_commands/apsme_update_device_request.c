/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> aps_commands.o -> apsme_update_device_request
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int apsme_update_device_request(int *param_1)

{
  short sVar1;
  short sVar2;
  int iVar3;
  int *piVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  int iStack_28;
  int iStack_24;
  
  iVar7 = 2;
  if (param_1 != (int *)0x0) {
    iVar3 = ezb_eui64_is_invalid();
    iVar7 = 2;
    if (iVar3 == 0) {
      piVar4 = (int *)nwk_get_extended_address();
      if ((*piVar4 == *param_1) && (piVar4[1] == param_1[1])) {
        apsme_update_device_indication(param_1);
        iVar7 = 0;
      }
      else {
        iVar3 = zmsg_alloc(0x3c);
        iVar7 = 1;
        if (iVar3 != 0) {
          aps_frame_append_cmd_hdr(0,1,1,0);
          zmsg_append_u8_isra_0(iVar3,6);
          iStack_28 = param_1[2];
          iStack_24 = param_1[3];
          zmsg_append_bytes(iVar3,8,&iStack_28);
          iStack_28 = CONCAT22(iStack_28._2_2_,(short)param_1[4]);
          zmsg_append_bytes(iVar3,2,&iStack_28);
          zmsg_append_u8_isra_0(iVar3,*(undefined1 *)((int)param_1 + 0x12));
          iVar7 = aps_secur_get_key_pair_by_addr(param_1);
          if (((iVar7 == 0) || ((*(ushort *)(iVar7 + 0x34) & 1) != 0)) &&
             (iVar7 = zmsg_alloc(0x2f), iVar7 != 0)) {
            aps_frame_append_cmd_hdr(0,1,0,0);
            uVar5 = zmsg_get_offset(iVar3);
            sVar1 = zmsg_get_length(iVar3);
            sVar2 = zmsg_get_offset(iVar3);
            iVar6 = zmsg_append_bytes_from_msg(iVar7,iVar3,uVar5,sVar1 - sVar2);
            if ((iVar6 != 0) || (iVar6 = aps_send_cmd(iVar7,param_1), iVar6 != 0)) {
              zmsg_free(iVar7);
            }
          }
          iVar7 = aps_send_cmd(iVar3,param_1);
          if (iVar7 != 0) {
            zmsg_free(iVar3);
          }
        }
      }
    }
  }
  return iVar7;
}

