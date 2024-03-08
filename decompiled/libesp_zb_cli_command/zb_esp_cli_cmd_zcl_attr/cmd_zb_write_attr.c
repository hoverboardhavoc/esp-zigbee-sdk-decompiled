/*
 * Last changed at upstream commit 2fe15bae2e4382ac99f249a0934066f5d5a5c684
 * https://github.com/espressif/esp-zigbee-sdk/commit/2fe15bae2e4382ac99f249a0934066f5d5a5c684
 * Upstream date: 2024-03-08 17:10:04 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.0(9d7e9ff2)
 * Source: libesp_zb_cli_command -> zb_esp_cli_cmd_zcl_attr.o -> cmd_zb_write_attr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void cmd_zb_write_attr(int param_1,undefined4 *param_2)

{
  bool bVar1;
  char *__s;
  char cVar2;
  uint uVar3;
  int iVar4;
  size_t sVar5;
  undefined4 uVar6;
  
  uVar3 = get_free_row_attr_table();
  if (param_1 - 7U < 2) {
    if (param_1 == 8) {
      iVar4 = strcmp((char *)param_2[7],"switch");
      if (iVar4 == 0) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
    }
    else {
      bVar1 = false;
    }
    if ((param_1 == 7) || (bVar1)) {
      if (uVar3 == 0xffffffff) {
        uVar6 = esp_log_timestamp();
        esp_log_write(1,&_L0,&_LC12,uVar6,&_L0);
      }
      else {
        cVar2 = parse_address(*param_2,uVar3 * 0x3c + 0x11420,1);
        (&DAT_00011428)[uVar3 * 0x3c] = cVar2;
        if (cVar2 == '\0') {
          uVar6 = esp_log_timestamp();
          esp_log_write(1,&_L0,&_LC13,uVar6,&_L0);
        }
        else {
          iVar4 = sscan_uint8(param_2[1],&DAT_00011429 + uVar3 * 0x3c);
          if (iVar4 == 0) {
            uVar6 = esp_log_timestamp();
            esp_log_write(1,&_L0,&_LC14,uVar6,&_L0);
          }
          else {
            iVar4 = parse_hex_u16(param_2[2],&DAT_0001142c + uVar3 * 0x3c);
            if (iVar4 == 0) {
              uVar6 = esp_log_timestamp();
              esp_log_write(1,&_L0,&_LC15,uVar6,&_L0);
            }
            else {
              iVar4 = parse_hex_u16(param_2[3],&DAT_0001142a + uVar3 * 0x3c);
              if (iVar4 == 0) {
                uVar6 = esp_log_timestamp();
                esp_log_write(1,&_L0,&_LC16,uVar6,&_L0);
              }
              else {
                iVar4 = parse_hex_u16(param_2[4],&DAT_0001142e + uVar3 * 0x3c);
                if (iVar4 == 0) {
                  uVar6 = esp_log_timestamp();
                  esp_log_write(1,&_L0,&_LC17,uVar6,&_L0);
                }
                else {
                  iVar4 = parse_hex_u8(param_2[5],&DAT_00011430 + uVar3 * 0x3c);
                  if (iVar4 == 0) {
                    uVar6 = esp_log_timestamp();
                    esp_log_write(1,&_L0,&_LC18,uVar6,&_L0);
                  }
                  else {
                    __s = (char *)param_2[6];
                    sVar5 = strlen(__s);
                    if ((&DAT_00011430)[uVar3 * 0x3c] == 'B') {
                      (&DAT_00011431)[uVar3 * 0x3c] = (char)sVar5;
                      strncpy((char *)(uVar3 * 0x3c + 0x11432),(char *)param_2[6],0x1f);
                    }
                    else {
                      iVar4 = parse_hex_str(__s,&DAT_00011431 + uVar3 * 0x3c,0x20,1);
                      if (iVar4 == 0) {
                        uVar6 = esp_log_timestamp();
                        esp_log_write(1,&_L0,&_LC19,uVar6,&_L0);
                        return;
                      }
                    }
                    if (bVar1) {
                      (&DAT_00011451)[uVar3 * 0x3c] = 1;
                    }
                    else {
                      (&DAT_00011451)[uVar3 * 0x3c] = 0;
                    }
                    *(undefined4 *)(&DAT_0001141c + uVar3 * 0x3c) = 1;
                    (&m_attr_table)[uVar3 * 0x3c] = 1;
                    iVar4 = zb_buf_get_out_delayed_ext_func(write_attr_send,uVar3 & 0xffff,0);
                    if (iVar4 != 0) {
                      uVar6 = esp_log_timestamp();
                      esp_log_write(1,&_L0,&_L0,uVar6,&_L0);
                      invalidate_row(uVar3 & 0xff);
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
    else {
      uVar6 = esp_log_timestamp();
      esp_log_write(1,&_L0,&_L0,uVar6,&_L0);
    }
  }
  else {
    uVar6 = esp_log_timestamp();
    esp_log_write(1,&_L0,&_L0,uVar6,&_L0);
  }
  return;
}

