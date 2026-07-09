/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> zcl_general_cmd.o -> zcl_config_report_cmd_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int zcl_config_report_cmd_req(void *param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  short sVar4;
  char *pcVar5;
  undefined1 auStack_60 [24];
  undefined1 auStack_48 [36];
  undefined4 uStack_24;
  
  memset(auStack_48,0,0x28);
  if ((((param_1 == (void *)0x0) || (*(short *)((int)param_1 + 0x1c) == 0)) ||
      (*(int *)((int)param_1 + 0x20) == 0)) ||
     (iVar1 = zcl_packet_init(auStack_48,*(uint *)((int)param_1 + 0x10) & 1), iVar1 != 0)) {
    iVar1 = -1;
  }
  else {
    memcpy(auStack_60,param_1,10);
    uVar3 = *(uint *)((int)param_1 + 0x10);
    iVar1 = zcl_cmd_to_packet(auStack_48,0,uVar3 & 1,uVar3 >> 1 & 1,uVar3 >> 2 & 1,
                              *(undefined2 *)((int)param_1 + 0xe),6,
                              *(undefined2 *)((int)param_1 + 0xc));
    if (iVar1 == 0) {
      iVar2 = 0;
      while ((iVar2 < (int)(uint)*(ushort *)((int)param_1 + 0x1c) &&
             (*(int *)((int)param_1 + 0x20) != 0))) {
        pcVar5 = (char *)(*(int *)((int)param_1 + 0x20) + iVar2 * 0x18);
        iVar1 = zmsg_append_u8(uStack_24,*pcVar5);
        if ((iVar1 != 0) ||
           (iVar1 = zmsg_append_le16(uStack_24,*(undefined2 *)(pcVar5 + 2)), iVar1 != 0)) goto _L0;
        if (*pcVar5 == '\0') {
          iVar1 = zmsg_append_u8(pcVar5[8]);
          if (((iVar1 != 0) ||
              (iVar1 = zmsg_append_le16(uStack_24,*(undefined2 *)(pcVar5 + 10)), iVar1 != 0)) ||
             (iVar1 = zmsg_append_le16(uStack_24,*(undefined2 *)(pcVar5 + 0xc)), iVar1 != 0))
          goto _L0;
          iVar1 = zcl_attr_type_is_analog(pcVar5[8]);
          if (iVar1 != 0) {
            sVar4 = *(short *)(pcVar5 + 0xc);
            if (sVar4 == 0) {
              sVar4 = *(short *)(pcVar5 + 10);
            }
            if (sVar4 == -1) {
              iVar1 = zmsg_append_u8(0);
            }
            else {
              iVar1 = zcl_packet_append_variable_attr_value(uStack_24,pcVar5[8],pcVar5 + 0x10);
            }
            goto _L0;
          }
        }
        else {
          iVar1 = zmsg_append_le16(uStack_24,*(undefined2 *)(pcVar5 + 8));
_L0:
          if (iVar1 != 0) goto _L0;
        }
        iVar2 = iVar2 + 1;
      }
      zcl_packet_send(auStack_48,(int)param_1 + 0x14);
      iVar1 = zcl_status_to_err();
      if (iVar1 == 0) {
        return 0;
      }
    }
  }
_L0:
  zcl_packet_free(auStack_48);
  return iVar1;
}

