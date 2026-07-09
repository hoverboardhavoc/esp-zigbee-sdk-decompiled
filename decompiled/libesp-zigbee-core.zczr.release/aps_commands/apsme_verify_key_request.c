/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> aps_commands.o -> apsme_verify_key_request
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int apsme_verify_key_request(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 local_30;
  undefined4 uStack_2c;
  
  iVar1 = 2;
  if (param_1 != 0) {
    iVar2 = ezb_eui64_is_invalid();
    iVar1 = 2;
    if (iVar2 == 0) {
      iVar1 = aps_secur_is_tc();
      if ((iVar1 == 0) &&
         ((iVar1 = aps_secur_is_centralized(), iVar1 != 0 || (*(char *)(param_1 + 8) == '\x04')))) {
        iVar1 = aps_secur_is_addr_tc(param_1);
        if ((iVar1 == 0) || (iVar1 = 0x3a6, *(char *)(param_1 + 8) != '\x03')) {
          iVar2 = aps_secur_get_key_pair_by_addr(param_1);
          iVar1 = 0x3ad;
          if (iVar2 != 0) {
            iVar3 = zmsg_alloc(0x2f);
            iVar1 = 1;
            if (iVar3 != 0) {
              aps_frame_append_cmd_hdr(0,1,0,0);
              zmsg_append_u8_isra_0(iVar3,0xf);
              iVar1 = 0x3aa;
              zmsg_append_u8_isra_0(iVar3,*(undefined1 *)(param_1 + 8));
              puVar4 = (undefined4 *)nwk_get_extended_address();
              local_30 = *puVar4;
              uStack_2c = puVar4[1];
              zmsg_append_bytes(iVar3,8,&local_30);
              if (*(char *)(param_1 + 8) == '\x04') {
                aps_secur_key_pair_get_hash(iVar2,&local_30);
                zmsg_append_bytes(iVar3,0x10,&local_30);
                iVar1 = aps_send_cmd(iVar3,param_1);
                if (iVar1 == 0) {
                  return 0;
                }
              }
              zmsg_free(iVar3);
            }
          }
        }
      }
      else {
        iVar1 = 0x3a3;
      }
    }
  }
  return iVar1;
}

