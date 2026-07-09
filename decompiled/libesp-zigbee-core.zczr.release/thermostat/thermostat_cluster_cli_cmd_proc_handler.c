/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> thermostat.o -> thermostat_cluster_cli_cmd_proc_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int thermostat_cluster_cli_cmd_proc_handler(int param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  ushort uStack_66;
  undefined4 uStack_64;
  void *pvStack_60;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  int iStack_54;
  undefined4 *puStack_50;
  uint uStack_4c;
  undefined1 auStack_48 [48];
  
  iVar1 = 1;
  memset(auStack_48,0,0x28);
  if (param_1 != 0) {
    iVar1 = 1;
    if (((*(byte *)(param_1 + 0x1a) & 8) != 0) &&
       (iVar1 = zcl_packet_init(auStack_48,*(byte *)(param_1 + 0x1a) >> 2 & 1), iVar1 == 0)) {
      uVar3 = 0x81;
      if (*(char *)(param_1 + 0x20) == '\0') {
        uStack_66 = 0;
        uStack_64 = 0;
        pvStack_60 = (void *)0x0;
        af_read_le8_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_66,&uStack_64);
        af_read_le8_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_66,(int)&uStack_64 + 2);
        af_read_le8_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_66,(int)&uStack_64 + 1);
        pvStack_60 = calloc(1,(uStack_64 & 0xff) * 6);
        uVar2 = 0;
        uVar3 = 0x89;
        if (pvStack_60 != (void *)0x0) {
          while( true ) {
            if ((uStack_64 & 0xff) <= uVar2) break;
            iVar1 = uVar2 * 6;
            af_read_le16_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_66,
                                (void *)((int)pvStack_60 + iVar1));
            if ((uStack_64 & 0x10000) == 0) {
              *(undefined2 *)((int)pvStack_60 + iVar1 + 2) = 0;
            }
            else {
              af_read_le16_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_66,
                                  (int)pvStack_60 + iVar1 + 2);
            }
            if ((uStack_64 & 0x20000) == 0) {
              *(undefined2 *)((int)pvStack_60 + iVar1 + 4) = 0;
            }
            else {
              af_read_le16_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_66,
                                  (int)pvStack_60 + iVar1 + 4);
            }
            uVar2 = uVar2 + 1 & 0xff;
          }
          uVar2 = zmsg_get_length();
          uVar3 = 0x80;
          if (uStack_66 <= uVar2) {
            uStack_5c = 0;
            uStack_58 = 0;
            iStack_54 = 0;
            puStack_50 = (undefined4 *)0x0;
            uStack_4c = 0;
            uVar3 = zcl_packet_to_message(&uStack_5c,param_1,0x80);
            if (uVar3 == 0) {
              uStack_4c = CONCAT31(uStack_4c._1_3_,0xfe);
              iStack_54 = param_1;
              puStack_50 = &uStack_64;
              zcl_core_action_schedule(0x3a,&uStack_5c,0);
              if ((uStack_4c & 0xff) != 0xfe) {
                uVar3 = uStack_4c & 0xff;
              }
            }
          }
        }
      }
      iVar1 = zcl_packet_setup_default_response(auStack_48,param_1,uVar3);
      if (iVar1 == 0) {
        zcl_packet_send(auStack_48,0);
      }
      else {
        zcl_packet_free(auStack_48);
      }
    }
  }
  return iVar1;
}

